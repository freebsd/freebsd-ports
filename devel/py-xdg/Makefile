# Created by: michael johnson <ahze@ahze.net>
#   $MCom: ports/devel/py-xdg/Makefile,v 1.4 2007/09/10 05:35:05 mezz Exp $

PORTNAME=	xdg
PORTVERSION=	0.28
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python library to access freedesktop.org standards

LICENSE=	LGPL20

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/xdg/BaseDirectory.py

.include <bsd.port.mk>
