# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	diaspora
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	http://diaspora.fs2downloads.com/ \
		http://www.freespacemods.net/e107_files/downloads/:freespacemods \
		http://copy.com/8wo3AQnYu0bj/:copy
DISTFILES=	Diaspora_R1_Linux.tar.lzma:freespacemods,DEFAULT \
		Diaspora_R1_Patch_1.1.tar.lzma:copy \
		Diaspora_R1_Patch_1.1.1.tar.lzma

MAINTAINER=	lightside@gmx.com
COMMENT=	Single and multiplayer space fighter combat game

LICENSE=	CCBYNCSAv3 VOLITION GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_CCBYNCSAv3=	Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported license
LICENSE_NAME_VOLITION=	Volition license
LICENSE_FILE_CCBYNCSAv3=	${WRKDIR_DIASPORA}/License.txt
LICENSE_FILE_VOLITION=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2=	${WRKDIR_DIASPORA}/wxlauncher/GPLv2.txt
LICENSE_PERMS_CCBYNCSAv3=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept
LICENSE_PERMS_VOLITION=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

LIB_DEPENDS+=	libjansson.so:devel/jansson \
		libpng.so:graphics/png \
		libogg.so:audio/libogg \
		libvorbisfile.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora

USES=	autoreconf jpeg lua:51 openal pkgconfig tar:lzma
USE_GL=	yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes

WRKDIR_DIASPORA=	${WRKDIR}/Diaspora_R1_Linux/Diaspora
WRKSRC=	${WRKDIR_DIASPORA}/fs2_open

PORTDATA=	data *.vp
PORTDOCS=	*
SUB_FILES=	fs2_open_${PORTNAME}
PLIST_FILES+=	bin/fs2_open_${PORTNAME} \
		libexec/fs2_open_${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES=	"Diaspora" "${COMMENT}" \
	"${PORTNAME}" "fs2_open_${PORTNAME}" \
	"Game;Simulation;" false

MANUAL_PACKAGE_BUILD=	very large distfile set (~1.8 GB)

OPTIONS_DEFINE=	DOCS INCJOYBTNS SPEECH WXLAUNCHER
OPTIONS_DEFAULT=	SPEECH WXLAUNCHER
INCJOYBTNS_DESC=	Increase a number of joystick buttons from 32 to 98
INCJOYBTNS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-increase_joy_buttons_fixed.patch
SPEECH_DESC=	Text to speech
SPEECH_CONFIGURE_ENABLE=	speech
WXLAUNCHER_DESC=	Use wxlauncher to manage application profile
WXLAUNCHER_RUN_DEPENDS=	wxlauncher:games/wxlauncher

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWXLAUNCHER}
PORTDATA+=	resources *.ini *.png *.bmp
SUB_FILES+=	fs2_open_${PORTNAME}_launcher
PLIST_FILES+=	bin/fs2_open_${PORTNAME}_launcher \
		%%DATADIR%%/fs2_open_${PORTNAME}

DESKTOP_ENTRIES+=	"Diaspora Launcher" "${COMMENT}" \
	"${PORTNAME}" "fs2_open_${PORTNAME}_launcher" \
	"Game;Simulation;" false
.endif

post-extract: .SILENT
.for v in 1.1 1.1.1
	(cd ${WRKDIR} && tar -xf Patch_Files.${v}.tar -C ${WRKDIR_DIASPORA} && \
		${RM} Patch_Files.${v}.tar)
.endfor
.if ${PORT_OPTIONS:MWXLAUNCHER}
	(cd ${WRKDIR_DIASPORA} && ${CP} -f pro00099.template.ini pro00099.ini)
# Backup data/cmdline_fso.cfg, because executable might merge it with
# user settings
	(cd ${WRKDIR_DIASPORA}/data && ${MV} -f cmdline_fso.cfg cmdline_fso.cfg.bak)
.endif

post-patch: .SILENT
.if ${PORT_OPTIONS:MWXLAUNCHER}
	${REINPLACE_CMD} -e \
		's|/PATH/TO/YOUR/DIASPORA/FOLDER/HERE|${DATADIR}|' \
		${WRKDIR_DIASPORA}/pro00099.ini
.endif
	${REINPLACE_CMD} -e '/^AC_INIT/s/3\.7\.1/${PORTNAME}/ ; \
		s/freebsd/${OPSYS:tl}/ ; \
		s/ -m64 -march=athlon64 -ansi// ; \
		s|/usr/local|${LOCALBASE}|' \
		${CONFIGURE_WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|(640x480)x16|(1024x768)x32|' \
		${BUILD_WRKSRC}/code/osapi/osapi_unix.cpp

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fs2_open_${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/code/fs2_open_${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec
	(cd ${WRKDIR_DIASPORA} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "README*.txt" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKDIR_DIASPORA} && ${COPYTREE_SHARE} "*.pdf *.rtf README.txt" \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog" \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKDIR_DIASPORA}/resources/modimg.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.if ${PORT_OPTIONS:MWXLAUNCHER}
	${INSTALL_SCRIPT} ${WRKDIR}/fs2_open_${PORTNAME}_launcher \
		${STAGEDIR}${PREFIX}/bin
# Create a symbolic link, which used by launcher
	${LN} -sf ${PREFIX}/libexec/fs2_open_${PORTNAME} ${STAGEDIR}${DATADIR}
.endif

add-plist-post: build-plist-empty

build-plist-empty: .SILENT
# Add required empty directories to TMPPLIST
	${FIND} ${STAGEDIR}${DATADIR}/data -type d -empty | \
		${SED} -e 's|^${STAGEDIR}|@dir |' >> ${TMPPLIST}

.include <bsd.port.mk>
