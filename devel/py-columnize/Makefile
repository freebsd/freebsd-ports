# $FreeBSD$

PORTNAME=	columnize
PORTVERSION=	0.3.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Format a simple (i.e. not nested) list into aligned columns

LICENSE=	MIT

MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:devel/py-nose@${PY_FLAVOR}

BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

EXTRA_PATCHES=	${FILESDIR}/extra-patch-____pkginfo____.py
NO_ARCH=	yes

.include <bsd.port.mk>
