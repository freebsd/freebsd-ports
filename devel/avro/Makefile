# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data serialization system

LICENSE=	APACHE20

USES=		metaport

OPTIONS_DEFINE=	C CPP PYTHON RUBY
OPTIONS_DEFAULT=C CPP PYTHON RUBY
C_DESC=		Install C library
CPP_DESC=	Install C++ library
PYTHON_DESC=	Install Python library
RUBY_DESC=	Install Ruby library

C_LIB_DEPENDS=		libavro.so:devel/avro-c
CPP_LIB_DEPENDS=	libavrocpp.so:devel/avro-cpp
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}avro>=0:devel/py-avro@${PY_FLAVOR}
PYTHON_USES=		python:env
RUBY_RUN_DEPENDS=	rubygem-avro>=0:devel/rubygem-avro

.include <bsd.port.mk>
