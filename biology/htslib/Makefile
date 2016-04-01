# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	htslib
PORTVERSION=	1.3
CATEGORIES=	biology devel

MAINTAINER=	cartwright@asu.edu
COMMENT=	C library for high-throughput sequencing data formats

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	samtools

USES=		autoreconf gmake perl5 shebangfix
USE_PERL5=	test
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
SHEBANG_FILES=	test/compare_sam.pl test/test.pl test/test_view.pl

OPTIONS_DEFINE=		CURL
OPTIONS_DEFAULT=	CURL

CURL_DESC=		Use libcurl for network file access (HTTPS and S3 support).
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	libcurl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DIR="${MKDIR}"

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
