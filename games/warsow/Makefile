# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warsow
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/warsow.mirror/Warsow%20${PORTVERSION} \
		http://www.warsow.net:1337/~warsow/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}_sdk
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	games@FreeBSD.org
COMMENT=	Futuristic, fast-paced first person shooter

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake

WRKSRC=		${WRKDIR}/source/source
ALL_TARGET=	game angelwrap
RELEASEDIR=	${WRKSRC}/release
AS_SDK_DIR=	${WRKSRC}/../libsrcs/angelscript/sdk

PLIST_FILES=	%%DATADIR%%/basewsw/game_${ARCH}.so \
		%%DATADIR%%/libs/angelwrap_${ARCH}.so
PLIST_DIRS=	%%DATADIR%%/basewsw %%DATADIR%%/libs %%DATADIR%%

OPTIONS_DEFINE=	CLIENT SERVER FTLIB REF_GL QF OPENAL IRC CIN TV_SRV DOCS
OPTIONS_DEFAULT=	CLIENT SERVER FTLIB REF_GL QF OPENAL IRC CIN TV_SRV

CLIENT_DESC=	Build game client
SERVER_DESC=	Build dedicated server
FTLIB_DESC=	Build FreeType library module
REF_GL_DESC=	Build reference OpenGL module
QF_DESC=	Build Qf sound module
OPENAL_DESC=	Build OpenAL sound module
IRC_DESC=	Build IRC client module
CIN_DESC=	Build Cinematics playback module
TV_SRV_DESC=	Build Warsow TV server

PORTDOCS=	*.rtf *.doc sourcecode_quickstart.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_XORG=	xi xrandr

ALL_TARGET+=	cgame ui client
PLIST_FILES+=	bin/warsow %%DATADIR%%/basewsw/cgame_${ARCH}.so \
		%%DATADIR%%/basewsw/ui_${ARCH}.so \
		share/pixmaps/warsow128x128.xpm

DESKTOP_ENTRIES="Warsow" "${COMMENT}" \
	"${PREFIX}/share/pixmaps/warsow128x128.xpm" "${PORTNAME}" \
	"Game;Shooter;" ""

. if ${PORT_OPTIONS:MFTLIB} || ${PORT_OPTIONS:MREF_GL}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
. endif

. if ${PORT_OPTIONS:MFTLIB}
LIB_DEPENDS+=	libfreetype.so:${PORTSDIR}/print/freetype2
ALL_TARGET+=	ftlib
PLIST_FILES+=	%%DATADIR%%/libs/ftlib_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MREF_GL}
USE_GL=		gl
USE_XORG+=	xinerama
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
ALL_TARGET+=	ref_gl
PLIST_FILES+=	%%DATADIR%%/libs/ref_gl_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MQF} || ${PORT_OPTIONS:MOPENAL}
LIB_DEPENDS+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
. endif

. if ${PORT_OPTIONS:MQF}
USE_SDL=	sdl
ALL_TARGET+=	qf
PLIST_FILES+=	%%DATADIR%%/libs/snd_qf_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MOPENAL}
USES+=		openal:al
ALL_TARGET+=	openal
PLIST_FILES+=	%%DATADIR%%/libs/snd_openal_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MIRC}
ALL_TARGET+=	irc
PLIST_FILES+=	%%DATADIR%%/libs/irc_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MCIN}
ALL_TARGET+=	cin
PLIST_FILES+=	%%DATADIR%%/libs/cin_${ARCH}.so
BUILD_DEPENDS+=	${LOCALBASE}/include/theora/theoradec.h:${PORTSDIR}/multimedia/libtheora
. endif
.endif

.if ${PORT_OPTIONS:MSERVER}
ALL_TARGET+=	ded
PLIST_FILES+=	bin/wsw_server
.endif

.if ${PORT_OPTIONS:MTV_SRV}
ALL_TARGET+=	tv_server
PLIST_FILES+=	bin/wswtv_server
.endif

post-patch: .SILENT
# Unmute build and link commands, respect CFLAGS
	${REINPLACE_CMD} -e 's|@$$(DO_CC|$$(DO_CC| ; /> Linking $$@/d ; \
		s|-O2 -fno-strict-aliasing -ffast-math -funroll-loops ||; \
		s| -msse2||' \
		${WRKSRC}/Makefile
# Adjust architecture names, get rid of ``freebsd_'' prefix
	${REINPLACE_CMD} -e 's/x86_64/amd64/ ; s/freebsd_//' \
		${WRKSRC}/gameshared/q_arch.h
# Search directory provided by warsow-data port instead of current (doing
# so allows us not to install any wrapper scripts)
	${REINPLACE_CMD} -e 's|path", "\.|path", "${DATADIR}|' \
		${WRKSRC}/qcommon/files.c
# Disable pure check for library files, because they are built and placed to
# ${DATADIR} base path instead of pack file(s)
	${REINPLACE_CMD} -e 's|pure \&\& !FS_IsPureFile|0 \&\& !FS_IsPureFile|' \
		${WRKSRC}/qcommon/library.c

do-install:
.for b in ${PLIST_FILES:Mbin/*:T}
	${INSTALL_PROGRAM} ${RELEASEDIR}/${b}.${ARCH} ${STAGEDIR}${PREFIX}/bin/${b}
.endfor
	cd ${RELEASEDIR} && ${COPYTREE_SHARE} "basewsw libs" ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/unix/warsow128x128.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/../../docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
