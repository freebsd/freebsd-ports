# New ports collection makefile for:	lrzip
# Date created:		2011-04-08
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	lrzip
PORTVERSION=	0.608
CATEGORIES=	archivers
MASTER_SITES=	http://ck.kolivas.org/apps/lrzip/ \
		http://files.gslin.org/Software/

MAINTAINER=	gslin@gslin.org
COMMENT=	Long Range ZIP or Lzma RZIP

LICENSE=	GPLv2

BUILD_DEPENDS=	nasm>=0:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	lzo2:${PORTSDIR}/archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-asm
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

MAN1=		lrunzip.1 \
		lrzcat.1 \
		lrzip.1 \
		lrztar.1 \
		lrzuntar.1
MAN5=		lrzip.conf.5

.include <bsd.port.mk>
