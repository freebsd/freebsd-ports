# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	bcftools
PORTVERSION=	1.3.1
CATEGORIES=	biology

MAINTAINER=	cartwright@asu.edu
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
# LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.3:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash

CONFLICTS_BUILD=openssl

USE_GITHUB=	yes
GH_ACCOUNT=	samtools

USES=		gmake perl5 shebangfix
USE_PERL5=	test
SUB_FILES=	pkg-message
SHEBANG_FILES=	vcfutils.pl plot-vcfstats plugins/color-chrs.pl test/test.pl

OPTIONS_DEFINE=	GPL
GPL_DESC=	Enable modules that rely on GPL code
OPTIONS_DEFAULT=	GPL

GPL_LIB_DEPENDS=	libgsl.so:math/gsl

.include <bsd.port.options.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DIR="${MKDIR}"

.if ${PORT_OPTIONS:MGPL}
MAKE_ENV+=	USE_GPL=1
LICENSE=	GPLv3
.endif

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

TEST_TARGET=	test

.include <bsd.port.mk>
