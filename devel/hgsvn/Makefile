# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hgsvn
PORTVERSION=	0.2.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Scripts to work locally on Subversion checkouts using Mercurial

LICENSE=	GPLv3

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		hg:${PORTSDIR}/devel/mercurial

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_ZIP=	yes
PYDISTUTILS_AUTOPLIST=	yes
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.mk>
