# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	samtools
PORTVERSION=	1.6
CATEGORIES=	biology

MAINTAINER=	cartwright@asu.edu
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.6:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes

USES=		autoreconf gmake ncurses perl5 python:env shebangfix
USE_PERL5=	test
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
SHEBANG_FILES=	misc/*.pl misc/*.py misc/plot-bamstats test/test.pl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

TEST_TARGET=	test

.include <bsd.port.mk>
