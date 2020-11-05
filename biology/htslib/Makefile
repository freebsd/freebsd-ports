# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	htslib
DISTVERSION=	1.11.0
CATEGORIES=	biology devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C library for high-throughput sequencing data formats

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake localbase pathfix perl5 shebangfix
USE_GITHUB=	yes
USE_PERL5=	test
USE_LDCONFIG=	yes

GH_ACCOUNT=		samtools
GNU_CONFIGURE=		yes
PATHFIX_MAKEFILEIN=	Makefile
SHEBANG_FILES=		test/*.pl

OPTIONS_DEFINE=		CURL
OPTIONS_DEFAULT=	CURL

CURL_DESC=		Use libcurl for network file access (HTTPS and S3 support).
CURL_USES=		ssl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	libcurl

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

TEST_TARGET=	test

.include <bsd.port.mk>
