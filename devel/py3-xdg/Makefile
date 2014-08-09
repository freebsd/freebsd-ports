# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$
#   $MCom: ports/trunk/devel/py3-xdg/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	xdg
PORTVERSION=	0.25
CATEGORIES=	devel python
MASTER_SITES=	http://people.freedesktop.org/~takluyver/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 3 library to access freedesktop.org standards

LICENSE=	LGPL20

USE_PYTHON=	3
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/xdg/BaseDirectory.py

.include <bsd.port.mk>
