PORTNAME=	netradiant
PORTVERSION=	20150621
PORTREVISION=	8
CATEGORIES=	games cad
MASTER_SITES=	http://ingar.intranifty.net/gtkradiant/files/ LOCAL/danfe \
		http://ingar.intranifty.net/gtkradiant/files/gamepacks/:gp
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} q3map2.6
EXTRACT_ONLY=	${_DISTFILES:Nq3map2.6}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fork of GtkRadiant v1.5 FPS games map editor
WWW=		http://ingar.intranifty.net/gtkradiant/

LICENSE=	GPLv2

BROKEN_armv6=		fails to build: h2data.armv6: No such file or directory
BROKEN_armv7=		fails to build: h2data.armv7: No such file or directory

LIB_DEPENDS=	libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

USES=		compiler:c++11-lang gl gmake gnome jpeg localbase:ldflags \
		pkgconfig tar:xz xorg
USE_GL=		gl glu
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk20 libxml2 pango pangox-compat
USE_XORG=	ice sm x11 xmu xt
MAKE_ENV=	BUILD=release DOWNLOAD_GAMEPACKS=no EXE=${ARCH} \
		RADIANT_ABOUTMSG="For ${OPSYS} ${OSREL} (${ARCH})"

SUB_FILES=	${PORTNAME}
SUB_LIST=	ARCH=${ARCH}
PLIST_SUB:=	${SUB_LIST}

OPTIONS_DEFINE=	GAMEPACK
OPTIONS_DEFAULT=	GAMEPACK
GAMEPACK_DESC=	Install gamepacks for some popular games
OPTIONS_SUB=	yes

GAMES=	DarkPlaces Doom3 ET Neverball Nexuiz OpenArena Osirion Quake1 \
	Quake2 Quake2World Quake3 Quake4 Quake Quetoo Tremulous UFOAI \
	Unvanquished Warsow Xonotic
GAMEPACK_DISTFILES=	${GAMES:S/$/Pack.zip:gp/}

post-patch:
	@${REINPLACE_CMD} -e 's,register ,,' \
		${WRKSRC}/libs/container/hashfunc.h
	@${REINPLACE_CMD} -e '/#include/s,sys/dir,dirent,' \
		${WRKSRC}/tools/quake2/qdata/qdata.c
	@${REINPLACE_CMD} -e 's,#ifndef WIN32,#ifdef NeXT,' \
		${WRKSRC}/tools/quake3/q3data/q3data.c
	@${GREP} -Rl --null __linux__ ${WRKSRC}/tools | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,__linux__,__${OPSYS}__,'

pre-install:
# Remove a copy of GNU GPL from what we are going to install
	@${RM} ${WRKSRC}/install/GPL.txt

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${RMDIR} ${WRKSRC}/install/games
	${CP} -a ${WRKSRC}/install/* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/q3map2.6 ${STAGEDIR}${PREFIX}/share/man/man6

do-install-GAMEPACK-on:
.for g in ${GAMES}
	${CP} -a ${WRKDIR}/${g}Pack/games ${WRKDIR}/${g}Pack/*.game \
		${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
