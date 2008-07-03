# New ports collection makefile for:	py-xdg
# Date created:		2004-06-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#   $MCom: ports/devel/py-xdg/Makefile,v 1.4 2007/09/10 05:35:05 mezz Exp $
#

PORTNAME=	xdg
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://people.freedesktop.org/~lanius/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A python library to access freedesktop.org standards

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pyxdg

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc|${LOCALBASE}/etc|g ; s|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/xdg/BaseDirectory.py \
			${WRKSRC}/xdg/IconTheme.py

.include <bsd.port.mk>
