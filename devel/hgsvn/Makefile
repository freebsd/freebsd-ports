# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hgsvn
PORTVERSION=	0.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Scripts to work locally on Subversion checkouts using Mercurial

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		hg:${PORTSDIR}/devel/mercurial

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

NO_STAGE=	yes

post-patch:
	@cd ${WRKSRC} && ${MV} setup.py setup.py.orig && ${GREP} -v use_setuptools setup.py.orig > setup.py && cd -

.include <bsd.port.mk>
