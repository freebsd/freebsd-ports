# $FreeBSD$

PORTNAME=	qmdnsengine
DISTVERSION=	0.1.0-13
DISTVERSIONSUFFIX=	-gbac0431
PORTREVISION=	2
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multicast DNS library for Qt applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	nitroshare
USE_QT=		core network buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
