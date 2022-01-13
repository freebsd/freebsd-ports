# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	lrzip
PORTVERSION=	0.631
CATEGORIES=	archivers
MASTER_SITES=	http://ck.kolivas.org/apps/lrzip/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Long Range ZIP or Lzma RZIP

LICENSE=	GPLv2

BUILD_DEPENDS=	nasm>=0:devel/nasm
LIB_DEPENDS=	liblzo2.so:archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-asm
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		alias cpe libtool pathfix perl5 shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/lrztar
USE_PERL5=	build
USE_LDCONFIG=	yes
CPE_VENDOR=	lrzip_project

CONFLICTS_INSTALL=	lrzsz # bin/lrz man/man1/lrz.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblrzip.so.0.0.0

.include <bsd.port.mk>
