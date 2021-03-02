# $FreeBSD$

PORTNAME=	pyinotify
PORTVERSION=	0.9.6
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP/source/p/pyinotify
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to (lib)inotify

LICENSE=	MIT

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		python:3.6+
USE_PYTHON=	distutils py3kplist

NO_ARCH=	YES

.include <bsd.port.mk>
