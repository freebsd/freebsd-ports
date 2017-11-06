# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	injeqt
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Dependency injection framework for Qt

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	vogel

USES=		cmake compiler:c++11-lib pathfix
USE_QT5=	core buildtools_build qmake_build testlib_build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DDISABLE_EXAMPLES:BOOL=ON \
		-DDISABLE_COVERAGE:BOOL=ON

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
