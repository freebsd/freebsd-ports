# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dateutil
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-dateutil-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Provides powerful extensions to the standard datetime module

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python-dateutil

# Fix incorrect permissions
post-patch:
	@${FIND} ${WRKSRC}/python_dateutil.egg-info -type f -exec ${CHMOD} ${SHAREMODE} {} ";"

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} test.py

.include <bsd.port.mk>
