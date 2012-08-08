# Ports collection makefile for:	hg-git
# Date created:		2009-10-24
# Whom:			Marco Broeder <marco.broeder@gmx.eu>
#
# $FreeBSD$
#

PORTNAME=	hg-git
PORTVERSION=	0.3.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

LICENSE=	GPLv2

RUN_DEPENDS=	${PKGNAMEPREFIX}dulwich>=0.8.5:${PORTSDIR}/devel/dulwich \
		mercurial>=2.0.2:${PORTSDIR}/devel/mercurial

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:S/-/_/}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
