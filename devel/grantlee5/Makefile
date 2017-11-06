# Created by: Tobias C. Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	grantlee
PORTVERSION=	${GRANTLEE_VERSION}
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://downloads.${PORTNAME}.org/
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	String template engine for Qt 5

LICENSE=	LGPL21

PORTSCOUT=	limit:^5\.

USE_QT5=	buildtools_build core gui qmake_build script
USES=		cmake:outsource compiler:c++11-lib grantlee:5,selfbuild
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=FALSE
USE_LDCONFIG=	yes

.include <bsd.port.mk>
