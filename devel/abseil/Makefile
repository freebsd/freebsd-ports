# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abseil
PORTVERSION=	20200923.2
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Abseil Common Libraries (C++)

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-cpp

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON

.include <bsd.port.mk>
