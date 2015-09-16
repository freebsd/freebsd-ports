# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitcollider
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	deskutils multimedia
MASTER_SITES=	SF/${PORTNAME}/Bitcollider/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bitzi metadata generator

GNU_CONFIGURE=	yes
USES=		libtool
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-lm

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/bitcollider/plugins/*.bcp

.include <bsd.port.mk>
