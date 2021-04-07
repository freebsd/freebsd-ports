PORTNAME=	numptyphysics
DISTVERSION=	0.3.r20090104
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Drawing physics-based puzzle game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang desktop-file-utils gnome sdl tar:bzip2 xorg
GNU_CONFIGURE=	yes
USE_SDL=	sdl image
USE_XORG=	x11
INSTALLS_ICONS=	yes

CONFIGURE_ENV=	AUTOMAKE="${TRUE}" ACLOCAL="${TRUE}" MISSING="${TRUE}"
LDFLAGS+=	-L${LOCALBASE}/lib -lpthread
CPPFLAGS+=	-I${LOCALBASE}/include -DINSTALL_BASE_PATH=\"\\\"${DATADIR}\\\"\"

CXXFLAGS+=	-Wno-c++11-narrowing

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	MOREFPS
OPTIONS_DEFAULT=MOREFPS
MOREFPS_DESC=	Smoother graphics support

post-patch:
	@${CHMOD} a+x ${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e 's|\(desktopentrydir=\).*|\1${PREFIX}/share/applications|' \
		-e '/stdc++/ d' \
		${WRKSRC}/configure ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|^Exec=.*|Exec=${PORTNAME}|; /^X-Icon-Path/ d' \
		${WRKSRC}/data/${PORTNAME}.desktop

post-patch-MOREFPS-on:
	@${REINPLACE_CMD} -e '/define RENDER_RATE/ s|20|60|' \
		${WRKSRC}/Config.h

post-build:
	@${STRIP_CMD} ${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
