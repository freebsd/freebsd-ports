# Created by: Tobias C. Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	grantlee
DISTVERSION=	${GRANTLEE_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.${PORTNAME}.org/
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	String template engine for Qt 5

LICENSE=	LGPL21

PORTSCOUT=	limit:^5\.

USE_QT=		buildtools_build core gui qmake_build script declarative
USES=		cmake compiler:c++11-lib grantlee:5,selfbuild qt:5
USE_CXXSTD=	c++11
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=FALSE
USE_LDCONFIG=	yes

.include <bsd.port.mk>
