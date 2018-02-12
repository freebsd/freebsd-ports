# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	libarea
PORTVERSION=	20160313
PORTREVISION=	6
CATEGORIES=	devel cad

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	CAM-related software for profile and pocketing operations

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs

USE_GITHUB=	yes
GH_ACCOUNT=	Heeks
GH_TAGNAME=	f1986ac

BINARY_ALIAS=	python=${PYTHON_CMD} \
		python-config=${PYTHON_CMD}-config
USES=		cmake:outsource python
USE_LDCONFIG=	yes

.include <bsd.port.mk>
