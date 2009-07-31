# New ports collection makefile for:	myBudget
# Date created:				2004 05 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	myBudget
PORTVERSION=	0.60
PORTREVISION=	6
CATEGORIES=	finance gnome
MASTER_SITES=	http://www.abisource.com/~msevior/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+-2 finance manager

NO_BUILD=	yes
USE_PYTHON=	yes
USE_GNOME=	pygnome2

post-patch:
	@${REINPLACE_CMD} -e 's|gobject.so|_gobject.so|' \
	    ${WRKSRC}/install.py

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} ./install.py ${PREFIX}

.include <bsd.port.mk>
