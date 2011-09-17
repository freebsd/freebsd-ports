# Ports collection makefile for:	hg-git
# Date created:		2009-10-24
# Whom:			Marco Broeder <marco.broeder@gmx.eu>
#
# $FreeBSD$
#

PORTNAME=	hg-git
PORTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

LICENSE=	GPLv2

RUN_DEPENDS=	${PKGNAMEPREFIX}dulwich>=0.8.0:${PORTSDIR}/devel/dulwich \
		mercurial>=1.9.0:${PORTSDIR}/devel/mercurial

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/thon//}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/hg_git-%%VERSION%%-%%PYVER%%.egg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
