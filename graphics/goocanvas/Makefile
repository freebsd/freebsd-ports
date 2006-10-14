# New ports collection makefile for:	goocanvas
# Date created:		2006-09-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/goocanvas/Makefile,v 1.1 2006/09/21 00:08:36 ahze Exp $

PORTNAME=	goocanvas
PORTVERSION=	0.4
CATEGORIES=	graphics
MASTER_SITES=	SOURCEFORGE

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Canvas widget for GTK+

USE_GNOME=	gtk20 gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
