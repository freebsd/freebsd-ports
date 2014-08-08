# $FreeBSD$

PORTNAME=	CuraEngine
PORTVERSION=	14.03
CATEGORIES=	cad

MAINTAINER=	cederom@tlen.pl
COMMENT=	Engine of slicing solution for RepRap 3D printers

LICENSE=	AGPLv3

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_COMMIT=	4c1043f
GH_TAGNAME=	${GH_COMMIT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/CuraEngine ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
