PORTNAME=	inotifyrecursive
PORTVERSION=	0.3.5
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Recursive inotify watches based on inotify-simple
WWW=		https://github.com/letorbi/inotifyrecursive

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}inotify-simple>=2.0.1_2:devel/py-inotify-simple@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
