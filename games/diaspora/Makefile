# Created by: lightside <lightside@gmx.com>

PORTNAME=	diaspora
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://diaspora.fs2downloads.com/ \
		http://sectorgame.com/fsfiles/uploads/Projects%20-%20Campaigns%20-%20TCs/Total%20Conversions/Diaspora/:sectorgame \
		http://sectorgame.com/fsfiles/uploads/Projects%20-%20Campaigns%20-%20TCs/Total%20Conversions/Diaspora/Diaspora%20%28Linux%29.tar.lzma?dummy=/:sectorgame1 \
		http://ftp.internat.freebsd.org/pub/FreeBSD/distfiles/:intfiles \
		http://ftp.tw.freebsd.org/distfiles/:twfiles
DISTFILES=	Diaspora_R1_Linux.tar.lzma:sectorgame1,DEFAULT \
		Diaspora_R1_Patch_1.1.tar.lzma:sectorgame,intfiles,twfiles,DEFAULT \
		Diaspora_R1_Patch_1.1.1.tar.lzma

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single and multiplayer space fighter combat game

LICENSE=	CC-BY-NC-SA-3.0 VOLITION GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_VOLITION=	Volition license
LICENSE_FILE_CC-BY-NC-SA-3.0=	${WRKDIR_DIASPORA}/License.txt
LICENSE_FILE_VOLITION=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2=	${WRKDIR_DIASPORA}/wxlauncher/GPLv2.txt
LICENSE_PERMS_VOLITION=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BROKEN_aarch64=		Fails to compile: cast from pointer to smaller type loses information

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libpng.so:graphics/png \
		libogg.so:audio/libogg \
		libvorbisfile.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora

USES=		autoreconf compiler:c++11-lang gl jpeg lua:51 openal pkgconfig \
		sdl tar:lzma
USE_CXXSTD=	gnu++98
USE_GL=		gl glu
USE_SDL=	sdl
GNU_CONFIGURE=	yes

LDFLAGS_i386=	-Wl,-znotext

WRKDIR_DIASPORA=${WRKDIR}/Diaspora_R1_Linux/Diaspora
WRKSRC=		${WRKDIR_DIASPORA}/fs2_open

PORTDATA=	data *.vp
PORTDOCS=	*
SUB_FILES=	fs2_open_${PORTNAME}
PLIST_FILES=	bin/fs2_open_${PORTNAME} \
		libexec/fs2_open_${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="Diaspora" "${COMMENT}" \
		"${PORTNAME}" "fs2_open_${PORTNAME}" \
		"Game;Simulation;" false

OPTIONS_DEFINE=		DOCS INCJOYBTNS SPEECH WXLAUNCHER
OPTIONS_DEFAULT=	SPEECH WXLAUNCHER
INCJOYBTNS_DESC=	Increase a number of joystick buttons from 32 to 98
INCJOYBTNS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-increase_joy_buttons_fixed.patch
SPEECH_DESC=		Text to speech
SPEECH_CONFIGURE_ENABLE=	speech
WXLAUNCHER_DESC=	Use wxlauncher to manage application profile
WXLAUNCHER_DESKTOP_ENTRIES=	"Diaspora Launcher" "${COMMENT}" \
			"${PORTNAME}" "fs2_open_${PORTNAME}_launcher" \
			"Game;Simulation;" false
WXLAUNCHER_PLIST_FILES=	bin/fs2_open_${PORTNAME}_launcher \
			${DATADIR}/fs2_open_${PORTNAME}
WXLAUNCHER_RUN_DEPENDS=	wxlauncher:games/wxlauncher
WXLAUNCHER_SUB_FILES=	fs2_open_${PORTNAME}_launcher
WXLAUNCHER_VARS=	PORTDATA+="resources *.ini *.png *.bmp"

POST_PLIST+=	build-plist-empty

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-fpermissive
.endif

post-extract: .SILENT
.for v in 1.1 1.1.1
	(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		Patch_Files.${v}.tar ${EXTRACT_AFTER_ARGS} -C ${WRKDIR_DIASPORA} \
		&& ${RM} Patch_Files.${v}.tar)
.endfor

post-extract-WXLAUNCHER-on: .SILENT
	(cd ${WRKDIR_DIASPORA} && ${CP} -f pro00099.template.ini pro00099.ini)
# Backup data/cmdline_fso.cfg, because executable might merge it with
# user settings
	(cd ${WRKDIR_DIASPORA}/data && ${MV} -f cmdline_fso.cfg cmdline_fso.cfg.bak)

post-patch: .SILENT
	${REINPLACE_CMD} -e '/^AC_INIT/s/3\.7\.1/${PORTNAME}/ ; \
		s/freebsd/${OPSYS:tl}/ ; \
		s/ -m64 -march=athlon64 -ansi// ; \
		s|/usr/local|${LOCALBASE}|' \
		${CONFIGURE_WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|(640x480)x16|(1024x768)x32|' \
		${BUILD_WRKSRC}/code/osapi/osapi_unix.cpp

post-patch-WXLAUNCHER-on: .SILENT
	${REINPLACE_CMD} -e \
		's|/PATH/TO/YOUR/DIASPORA/FOLDER/HERE|${DATADIR}|' \
		${WRKDIR_DIASPORA}/pro00099.ini

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fs2_open_${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/code/fs2_open_${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec
	(cd ${WRKDIR_DIASPORA} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKDIR_DIASPORA}/resources/modimg.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "README*.txt" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKDIR_DIASPORA} && ${COPYTREE_SHARE} "*.pdf *.rtf README.txt" \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog" \
		${STAGEDIR}${DOCSDIR})

do-install-WXLAUNCHER-on:
	${INSTALL_SCRIPT} ${WRKDIR}/fs2_open_${PORTNAME}_launcher \
		${STAGEDIR}${PREFIX}/bin
# Create a symbolic link, which used by launcher
	${LN} -sf ${PREFIX}/libexec/fs2_open_${PORTNAME} ${STAGEDIR}${DATADIR}

build-plist-empty: .SILENT
# Add required empty directories to TMPPLIST
	${FIND} ${STAGEDIR}${DATADIR}/data -type d -empty | \
		${SED} -e 's|^${STAGEDIR}|@dir |' >> ${TMPPLIST}

.include <bsd.port.post.mk>
