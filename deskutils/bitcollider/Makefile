# New ports collection makefile for:	bitcollider
# Date created:		7 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitcollider
PORTVERSION=	0.6.0
CATEGORIES=	deskutils multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Bitzi metadata generator

HAS_CONFIGURE=	yes
CFLAGS+=	-lm
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|g' ${WRKSRC}/configure

.include <bsd.port.mk>
