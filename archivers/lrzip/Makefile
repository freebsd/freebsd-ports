PORTNAME=	lrzip
PORTVERSION=	0.651
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://ck.kolivas.org/apps/lrzip/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Long Range ZIP or Lzma RZIP

LICENSE=	GPLv2

BUILD_DEPENDS=	nasm>=0:devel/nasm
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	ac_cv_prog_ASM_PROG='no '
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		alias cpe libtool perl5 shebangfix tar:xz
SHEBANG_FILES=	${WRKSRC}/lrztar
USE_PERL5=	build
USE_LDCONFIG=	yes
CPE_VENDOR=	lrzip_project

CONFLICTS_INSTALL=	lrzsz # bin/lrz share/man/man1/lrz.1.gz

.include <bsd.port.mk>
