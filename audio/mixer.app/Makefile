# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mixer.app
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Another mixer intended for the windowmaker dockapp

PLIST_FILES=	bin/Mixer.app
WRKSRC=		${WRKDIR}/Mixer.app-${PORTVERSION}
CXXFLAGS+=	-fno-rtti -fno-exceptions -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXpm -lXext -lX11
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"

USES=		xorg
USE_XORG=	xpm xext x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
