# ex:ts=8
# Ports collection makefile for:	transcalc
# Date created:			Sep 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	transcalc
PORTVERSION=	0.14
PORTREVISION=	8
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A analysis and synthesis tool for RF and microwave transmission lines

USE_GNOME=	gnometarget gtk20
GNU_CONFIGURE=	yes

MAN1=	transcalc.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
