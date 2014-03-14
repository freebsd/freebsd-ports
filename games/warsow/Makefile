# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warsow
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	SF/warsow.mirror/Warsow%201.02 \
		http://www.warsow.net:1337/~warsow/${PORTVERSION:R}${PORTVERSION:E}/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}${PORTVERSION:E}_sdk
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Futuristic, fast-paced first person shooter

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${DATADIR}/basewsw/data0_10.pk3:${PORTSDIR}/games/warsow-data

ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_UNSAFE=yes

USES=		dos2unix gmake
DOS2UNIX_FILES=	ui/as/asbind.h

WRKSRC=		${WRKDIR}/${DISTNAME}/source
ALL_TARGET=	game angelwrap
RELEASEDIR=	${WRKSRC}/release
AS_SDK_DIR=	${WRKSRC}/../libsrcs/angelscript/angelSVN/sdk

PLIST_FILES=	%%DATADIR%%/basewsw/game_${ARCH}.so \
		%%DATADIR%%/libs/angelwrap_${ARCH}.so
PLIST_DIRS=	%%DATADIR%%/libs

OPTIONS_DEFINE=	CLIENT SERVER QF OPENAL IRC CIN TV_SRV
OPTIONS_DEFAULT=	CLIENT SERVER QF OPENAL IRC CIN TV_SRV

CLIENT_DESC=	Build game client
SERVER_DESC=	Build dedicated server
QF_DESC=	Build Qf sound module
OPENAL_DESC=	Build OpenAL sound module
IRC_DESC=	Build IRC client module
CIN_DESC=	Build Cinematics playback module
TV_SRV_DESC=	Build Warsow TV server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
				libpng15.so:${PORTSDIR}/graphics/png \
				libfreetype.so:${PORTSDIR}/print/freetype2
PATCH_DEPENDS=	${DATADIR}/basewsw/ui_porkui.pk3:${PORTSDIR}/games/warsow-data
USE_GL=		gl
USE_SDL=	sdl
USE_XORG=	xinerama xxf86dga xrandr
ALL_TARGET+=	cgame ui client
PLIST_FILES+=	bin/warsow %%DATADIR%%/basewsw/cgame_${ARCH}.so \
		%%DATADIR%%/basewsw/ui_${ARCH}.so \
		%%DATADIR%%/basewsw/ui/porkui/template.rml \
		share/pixmaps/warsow128x128.xpm
PLIST_DIRS+=	%%DATADIR%%/basewsw/ui \
		%%DATADIR%%/basewsw/ui/porkui

DESKTOP_ENTRIES="Warsow" "${COMMENT}" \
	"${PREFIX}/share/pixmaps/warsow128x128.xpm" "${PORTNAME}" \
	"Game;" false

. if ${PORT_OPTIONS:MQF} || ${PORT_OPTIONS:MOPENAL}
LIB_DEPENDS+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
. endif

. if ${PORT_OPTIONS:MQF}
USE_SDL=	sdl
ALL_TARGET+=	qf
PLIST_FILES+=	%%DATADIR%%/libs/snd_qf_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MOPENAL}
USES+= openal:al
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

pre-patch: .SILENT
.if ${PORT_OPTIONS:MCLIENT}
	${MKDIR} ${RELEASEDIR}/basewsw
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DATADIR}/basewsw/ui_porkui.pk3 --include="ui/porkui/template.rml" -C ${RELEASEDIR}/basewsw ${EXTRACT_AFTER_ARGS}
.endif

post-patch: .SILENT
# Unmute build and link commands, respect CFLAGS
	${REINPLACE_CMD} -e 's|@$$(DO_CC|$$(DO_CC| ; /> Linking $$@/d ; \
		s|-O2 -fno-strict-aliasing -ffast-math -funroll-loops ||; \
		s| -msse2||' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|-g ||' \
		${AS_SDK_DIR}/angelscript/projects/gnuc/makefile
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
# Fix issue with utf8 characters for console and
# return checks for delete character (ASCII code 127) from 0.62 version
	${REINPLACE_CMD} -e '/x11display.ic = 0;/d; \
		s|Key_CharEvent( key, wc );|if ( wc != 127 ) Key_CharEvent( key, wc );|' \
		${WRKSRC}/unix/unix_input.c

do-install:
.for b in ${PLIST_FILES:Mbin/*:T}
	${INSTALL_PROGRAM} ${RELEASEDIR}/${b}.${ARCH} ${STAGEDIR}${PREFIX}/bin/${b}
.endfor
	cd ${RELEASEDIR} && ${COPYTREE_SHARE} "basewsw libs" ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/unix/warsow128x128.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps
.endif

.include <bsd.port.mk>
