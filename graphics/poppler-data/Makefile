# New ports collection makefile for:	poppler-data
# Date created:		2006-09-30
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/graphics/poppler-data/Makefile,v 1.1 2010/07/20 08:17:51 kwm Exp $
#

PORTNAME=	poppler-data
PORTVERSION=	0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Poppler encoding data

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
