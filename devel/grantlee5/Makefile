PORTNAME=	grantlee
DISTVERSION=	${GRANTLEE_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.${PORTNAME}.org/
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	String template engine for Qt 5
WWW=		https://github.com/steveire/grantlee

LICENSE=	LGPL21

DEPRECATED=	Depends on deprecated Qt5, has no consumers
EXPIRATION_DATE=	2026-10-31

PORTSCOUT=	limit:^5\.

USE_QT=		core declarative gui network script \
		buildtools:build qmake:build
USES=		cmake compiler:c++11-lib grantlee:5,selfbuild qt:5
USE_CXXSTD=	c++11
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=FALSE
USE_LDCONFIG=	yes

.include <bsd.port.mk>
