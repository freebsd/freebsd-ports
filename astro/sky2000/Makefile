# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sky2000
PORTVERSION=	0.2
CATEGORIES=	astro
MASTER_SITES=	SF/nova/catalogs/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary representation of the Sky2000 star catalog

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/nova

post-patch:
	@${REINPLACE_CMD} -e 's,/nova/,/share/nova/,' ${WRKSRC}/configure

.include <bsd.port.mk>
