# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warsow
PORTVERSION=	1.51
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://update.warsow.net/mirror/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}_sdk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Futuristic, fast-paced first person shooter

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	${DATADIR}/basewsw/data1_15.pk3:games/warsow-data

ONLY_FOR_ARCHS=	i386 amd64

USES=		alias gmake compiler:c++11-lang

WRKSRC=		${WRKDIR}/source/source
ALL_TARGET=	game angelwrap
RELEASEDIR=	${WRKSRC}/release
AS_SDK_DIR=	${WRKSRC}/../libsrcs/angelscript/sdk
LDFLAGS=	-L${LOCALBASE}/lib

PORTDATA=	*
PORTDOCS=	*.rtf *.doc sourcecode_quickstart.txt

OPTIONS_DEFINE=	CLIENT SERVER FTLIB REF_GL QF OPENAL IRC CIN TV_SRV DOCS XRANDR
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
XRANDR_DESC=	Xrandr support (may be broken with nvidia-driver)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_XORG=	xi

ALL_TARGET+=	cgame ui client
PLIST_FILES+=	bin/warsow \
		share/pixmaps/warsow128x128.xpm

DESKTOP_ENTRIES="Warsow" "${COMMENT}" \
	"${PREFIX}/share/pixmaps/warsow128x128.xpm" "${PORTNAME}" \
	"Game;Shooter;" false

. if ${PORT_OPTIONS:MFTLIB} || ${PORT_OPTIONS:MREF_GL}
LIB_DEPENDS+=	libpng.so:graphics/png
. endif

. if ${PORT_OPTIONS:MFTLIB}
LIB_DEPENDS+=	libfreetype.so:print/freetype2
ALL_TARGET+=	ftlib
. endif

. if ${PORT_OPTIONS:MREF_GL}
USE_GL=		gl
USE_XORG+=	xinerama
USES+=		jpeg
ALL_TARGET+=	ref_gl
. endif

. if ${PORT_OPTIONS:MQF} || ${PORT_OPTIONS:MOPENAL}
LIB_DEPENDS+=	libvorbisfile.so:audio/libvorbis
. endif

. if ${PORT_OPTIONS:MQF}
USE_SDL=	sdl
ALL_TARGET+=	qf
. endif

. if ${PORT_OPTIONS:MOPENAL}
USES+=		openal:al
ALL_TARGET+=	openal
. endif

. if ${PORT_OPTIONS:MIRC}
ALL_TARGET+=	irc
. endif

. if ${PORT_OPTIONS:MCIN}
ALL_TARGET+=	cin
BUILD_DEPENDS+=	${LOCALBASE}/include/theora/theoradec.h:multimedia/libtheora
. endif

. if ${PORT_OPTIONS:MXRANDR}
USE_XORG+=	xrandr
. else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-no-xrandr
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

.if ${OPSYS} == FreeBSD
SWAPARCH=	s/x86_64/amd64/
.endif

post-patch: .SILENT
# Unmute build and link commands, respect CFLAGS
	${REINPLACE_CMD} -e 's|@$$(DO_CC|$$(DO_CC| ; /> Linking $$@/d ; \
		s|-O2 -fno-strict-aliasing -ffast-math -funroll-loops ||; \
		s| -msse2||' \
		${WRKSRC}/Makefile
# Adjust architecture names, get rid of ``freebsd_'' prefix
	${REINPLACE_CMD} -e 's/freebsd_//; ${SWAPARCH}' \
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
	cd ${WRKDIR}/docs && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
