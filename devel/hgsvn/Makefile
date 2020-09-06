# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hgsvn
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Scripts to work locally on Subversion checkouts using Mercurial

LICENSE=	GPLv3

RUN_DEPENDS=	svn:devel/subversion \
		${PY_MERCURIAL} \
		${PYTHON_PKGNAMEPREFIX}hglib>0:devel/py-hglib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

NO_ARCH=	YES

.include <bsd.port.mk>
