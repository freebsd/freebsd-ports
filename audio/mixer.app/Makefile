PORTNAME=	mixer.app
DISTVERSION=	1.8.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another mixer intended for the windowmaker dockapp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg
USE_XORG=	x11 xext xpm

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"
CXXFLAGS+=	-fno-rtti -fno-exceptions -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXpm -lXext -lX11

WRKSRC=		${WRKDIR}/Mixer.app-${PORTVERSION}

PLIST_FILES=	bin/Mixer.app

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
