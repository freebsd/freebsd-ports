# New ports collection makefile for:	myBudget
# Date created:				2004 05 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	myBudget
PORTVERSION=	0.60
PORTREVISION=	2
CATEGORIES=	finance gnome
MASTER_SITES=	http://www.abisource.com/~msevior/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+-2 finance manager

NO_BUILD=	yes
USE_PYTHON=	yes
USE_GNOME=	pygnome2

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} ./install.py ${PREFIX}

.include <bsd.port.mk>
