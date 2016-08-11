# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	samtools
PORTVERSION=	1.3.1
CATEGORIES=	biology

MAINTAINER=	cartwright@asu.edu
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.3:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes

USES=		autoreconf gmake ncurses perl5 shebangfix
USE_PERL5=	test
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
SHEBANG_FILES=	misc/*.pl misc/plot-bamstats test/test.pl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DIR="${MKDIR}"

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' ${WRKSRC}/configure.ac
	${CP} ${FILESDIR}/ax_with_htslib.m4 ${WRKSRC}/
	${CP} ${FILESDIR}/ax_with_curses.m4 ${WRKSRC}/

.include <bsd.port.mk>
