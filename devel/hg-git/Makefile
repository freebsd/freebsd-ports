# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	hg-git
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

LICENSE=	GPLv2

RUN_DEPENDS=	${PKGNAMEPREFIX}dulwich>=0.8.7:${PORTSDIR}/devel/dulwich \
		mercurial>=2.5.2:${PORTSDIR}/devel/mercurial \
		${PKGNAMEPREFIX}ordereddict>=1.1:${PORTSDIR}/devel/py-ordereddict


USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/-/_/}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
