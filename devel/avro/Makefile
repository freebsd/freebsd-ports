PORTNAME=	avro
PORTVERSION=	1.12.1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data serialization system
WWW=		https://avro.apache.org/ \
		https://github.com/apache/avro

LICENSE=	APACHE20

USES=		metaport

OPTIONS_DEFINE=	C CPP PERL PYTHON RUBY
OPTIONS_DEFAULT=C CPP PERL PYTHON RUBY
C_DESC=		Install C library
CPP_DESC=	Install C++ library
PERL_DESC=	Install Perl library
PYTHON_DESC=	Install Python library
RUBY_DESC=	Install Ruby library

C_BUILD_DEPENDS=	avro-c>=${PORTVERSION}<${PORTVERSION}_99:devel/avro-c
C_LIB_DEPENDS=		libavro.so:devel/avro-c
CPP_BUILD_DEPENDS=	avro-cpp>=${PORTVERSION}<${PORTVERSION}_99:devel/avro-cpp
CPP_LIB_DEPENDS=	libavrocpp.so:devel/avro-cpp
PERL_RUN_DEPENDS=	p5-Avro>=${PORTVERSION}<${PORTVERSION}_99:devel/p5-Avro
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}avro>=${PORTVERSION}<${PORTVERSION}_99:devel/py-avro@${PY_FLAVOR}
PYTHON_USES=		python:env
RUBY_RUN_DEPENDS=	rubygem-avro>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-avro

.include <bsd.port.mk>
