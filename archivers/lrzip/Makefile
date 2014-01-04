# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	lrzip
PORTVERSION=	0.614
CATEGORIES=	archivers
MASTER_SITES=	http://ck.kolivas.org/apps/lrzip/ \
		http://files.gslin.org/Software/

MAINTAINER=	gslin@gslin.org
COMMENT=	Long Range ZIP or Lzma RZIP

LICENSE=	GPLv2

BUILD_DEPENDS=	nasm>=0:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-asm
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes
USES=	gmake pathfix perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
