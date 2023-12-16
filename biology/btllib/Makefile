PORTNAME=	btllib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bioinformatics Technology Lab common code library
WWW=		https://github.com/bcgsc/btllib

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		samtools:biology/samtools \
		cmake:devel/cmake-core
LIB_DEPENDS=	libsdsl.so:devel/sdsl-lite
RUN_DEPENDS=	samtools:biology/samtools

USES=		meson pkgconfig python:build shebangfix

SHEBANG_FILES=	scripts/*

USE_GITHUB=	yes
GH_ACCOUNT=	bcgsc
GH_TUPLE=	p-ranav:argparse:15d745f:argparse/subprojects/argparse \
		skystrife:cpptoml:fededad:cpptoml/subprojects/cpptoml

BINARY_ALIAS=	python3=${PYTHON_CMD} # python3-config=${PYTHON_CMD}-config # installs python binding into a wrong location, see https://github.com/bcgsc/btllib/issues/111

.include <bsd.port.mk>
