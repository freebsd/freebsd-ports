# ex:ts=8
# Ports collection makefile for:	sky2000
# Date created:			Apr 16, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sky2000
PORTVERSION=	0.2
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nova

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A binary representation of the Sky2000 star catalog

GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/nova

post-patch:
	@${REINPLACE_CMD} -e 's,/nova/,/share/nova/,' ${WRKSRC}/configure

.include <bsd.port.mk>
