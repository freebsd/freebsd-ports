PORTNAME=	samtools
DISTVERSION=	1.23.1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for manipulating next-generation sequencing data
WWW=		https://www.htslib.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.22:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf cpe gmake localbase ncurses perl5 python:env shebangfix

USE_GITHUB=	yes

USE_PERL5=	test
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
SHEBANG_FILES=	misc/*.pl misc/plot-bamstats test/test.pl

CONFIGURE_ARGS=	--with-htslib=system

TEST_TARGET=	test

CPE_VENDOR=	htslib

.include <bsd.port.mk>
