# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hgsvn
PORTVERSION=	0.3.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Scripts to work locally on Subversion checkouts using Mercurial

LICENSE=	GPLv3

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		hg:${PORTSDIR}/devel/mercurial

USES=		python zip
USE_PYTHON=	distutils autoplist
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

NO_ARCH=	YES

.include <bsd.port.mk>
