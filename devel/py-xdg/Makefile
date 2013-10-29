# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$
#   $MCom: ports/devel/py-xdg/Makefile,v 1.4 2007/09/10 05:35:05 mezz Exp $

PORTNAME=	xdg
PORTVERSION=	0.19
CATEGORIES=	devel python
MASTER_SITES=	http://people.freedesktop.org/~lanius/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A python library to access freedesktop.org standards

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pyxdg

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/xdg/BaseDirectory.py

.include <bsd.port.mk>
