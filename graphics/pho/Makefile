# New ports collection makefile for:   pho
# Date created:        10 April 2003
# Whom:                Roland Jesse <roland.jesse@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pho
PORTVERSION=	0.9.1
CATEGORIES=	graphics
MASTER_SITES=	http://shallowsky.com/software/pho/

MAINTAINER=	roland.jesse@gmx.net
COMMENT=	A lightweight image viewer

USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf gtk12
USE_REINPLACE=	yes

MAN1=		pho.1

do-configure:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|make|gmake|g' Makefile)
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|install -D|install|g' Makefile)

.include <bsd.port.mk>
