# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$
#   $MCom: ports/devel/py-xdg/Makefile,v 1.4 2007/09/10 05:35:05 mezz Exp $

PORTNAME=	xdg
PORTVERSION=	0.25
CATEGORIES=	devel python
MASTER_SITES=	http://people.freedesktop.org/~takluyver/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 2 library to access freedesktop.org standards

LICENSE=	LGPL20

USES=		python:2
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/xdg/BaseDirectory.py

.include <bsd.port.mk>
