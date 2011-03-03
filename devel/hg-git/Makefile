# Ports collection makefile for:	hg-git
# Date created:		2009-10-24
# Whom:			Marco Broeder <marco.broeder@gmx.eu>
#
# $FreeBSD$
#

PORTNAME=	hg-git
PORTVERSION=	0.2.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

RUN_DEPENDS=	${PKGNAMEPREFIX}dulwich>=0.7.0:${PORTSDIR}/devel/dulwich \
		mercurial>=1.7.5:${PORTSDIR}/devel/mercurial

LICENSE=	GPLv2

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/thon//}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/hg_git-%%VERSION%%-%%PYVER%%.egg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
