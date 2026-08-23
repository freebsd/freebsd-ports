PORTNAME=	lrzip
DISTVERSION=	0.7.2
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/ckolivas/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Long Range ZIP or Lzma RZIP
WWW=		https://github.com/ckolivas/lrzip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Only 64-bit platforms are supported

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2

USES=		cpe libtool localbase:ldflags perl5 shebangfix tar:xz
CPE_VENDOR=	long_range_zip_project
CPE_PRODUCT=	long_range_zip
USE_PERL5=	build
SHEBANG_FILES=	${WRKSRC}/lrztar

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	lrzsz # bin/lrz share/man/man1/lrz.1.gz

.include <bsd.port.mk>
