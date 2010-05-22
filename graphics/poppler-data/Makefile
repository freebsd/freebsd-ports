# New ports collection makefile for:	poppler-data
# Date created:		2006-09-30
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poppler-data
PORTVERSION=	0.4.2
CATEGORIES=	graphics
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Poppler encoding data

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
