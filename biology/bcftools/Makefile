# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	bcftools
PORTVERSION=	1.6
CATEGORIES=	biology

MAINTAINER=	cartwright@asu.edu
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
# LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.6:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash

CONFLICTS_BUILD=openssl

USE_GITHUB=	yes
GH_ACCOUNT=	samtools

USES=		autoreconf gmake perl5 python:env shebangfix
USE_PERL5=	test
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
SHEBANG_FILES=	misc/* test/test.pl

OPTIONS_DEFINE=	GPL
GPL_DESC=	Enable modules that rely on GPL code
OPTIONS_DEFAULT=	GPL

GPL_LIB_DEPENDS=	libgsl.so:math/gsl

.include <bsd.port.options.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${PORT_OPTIONS:MGPL}
MAKE_ENV+=	USE_GPL=1
LICENSE=	GPLv3
.endif

TEST_TARGET=	test

post-patch:
	@${GREP} -q '@PORTVERSION@' ${WRKSRC}/configure.ac || (echo "@PORTVERSION@ in file/patch-configure.ac is overwritten probably due to using 'make makepatch'"; exit 1)
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
