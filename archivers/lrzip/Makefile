PORTNAME=	lrzip
DISTVERSIONPREFIX=	v
DISTVERSION=	0.660
CATEGORIES=	archivers

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Long Range ZIP or Lzma RZIP

LICENSE=	GPLv2

USES=		autoreconf cpe libtool perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ckolivas
GH_PROJECT=	lrzip

BUILD_DEPENDS=	nasm>=0:devel/nasm
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	ac_cv_prog_ASM_PROG='no '
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LDFLAGS+=	-L${LOCALBASE}/lib
SHEBANG_FILES=	${WRKSRC}/lrztar
USE_PERL5=	build
CPE_VENDOR=	lrzip_project

CONFLICTS_INSTALL=	lrzsz # bin/lrz share/man/man1/lrz.1.gz

.include <bsd.port.mk>
