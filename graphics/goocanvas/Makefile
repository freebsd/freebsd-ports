# New ports collection makefile for:	goocanvas
# Date created:		2006-09-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/goocanvas/Makefile,v 1.3 2008/02/27 16:19:11 ahze Exp $

PORTNAME=	goocanvas
PORTVERSION=	0.14
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Canvas widget for GTK+

USE_GNOME=	gtk20 gnomehack ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
