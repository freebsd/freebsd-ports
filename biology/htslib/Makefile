PORTNAME=	htslib
DISTVERSION=	1.22
CATEGORIES=	biology devel
# Github generated distfiles are incomplete, so use custom tarball
MASTER_SITES=	https://github.com/samtools/htslib/releases/download/${DISTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C library for high-throughput sequencing data formats
WWW=		https://www.htslib.org/

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf cpe gmake localbase:ldflags perl5 shebangfix tar:bzip2
USE_PERL5=	test
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKE_ARGS_armv6=	HTS_HAVE_NEON=
MAKE_ARGS_armv7=	HTS_HAVE_NEON=
MAKE_ARGS=		${MAKE_ARGS_${ARCH}}
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
