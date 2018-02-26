# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.8.2
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data serialization system

LICENSE=	APACHE20

USES=		metaport

OPTIONS_DEFINE=	C CPP PYTHON
OPTIONS_DEFAULT=C CPP PYTHON
C_DESC=		Install C library
CPP_DESC=	Install C++ library
PYTHON_DESC=	Install Python library

C_LIB_DEPENDS=		libavro.so:devel/avro-c
CPP_LIB_DEPENDS=	libavrocpp.so:devel/avro-cpp
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}avro>=0:devel/py-avro@${PY_FLAVOR}
PYTHON_USES=		python:env

.include <bsd.port.mk>
