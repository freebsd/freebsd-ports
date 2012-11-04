# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	hg-git
PORTVERSION=	0.3.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>=0.8.5:${PORTSDIR}/devel/dulwich \
		mercurial>=2.3.2:${PORTSDIR}/devel/mercurial

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/-/_/}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
