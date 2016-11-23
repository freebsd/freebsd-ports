# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	libarea
PORTVERSION=	20160313
PORTREVISION=	1
CATEGORIES=	devel cad

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	CAM-related software for profile and pocketing operations

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	python-config:lang/python
LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs

USE_GITHUB=	yes
GH_ACCOUNT=	Heeks
GH_TAGNAME=	f1986ac

USES=		cmake:outsource python
USE_LDCONFIG=	yes

.include <bsd.port.mk>
