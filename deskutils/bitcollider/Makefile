# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitcollider
PORTVERSION=	0.6.0
CATEGORIES=	deskutils multimedia
MASTER_SITES=	SF/${PORTNAME}/Bitcollider/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Bitzi metadata generator

HAS_CONFIGURE=	yes
CFLAGS+=	-lm
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|g' ${WRKSRC}/configure

.include <bsd.port.mk>
