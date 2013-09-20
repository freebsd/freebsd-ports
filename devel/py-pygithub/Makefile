# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygithub
PORTVERSION=	1.8.0
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyGithub-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Use the full Github API v3 with Python

LICENSE=	LGPL3

USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_PKGNAME=	PyGithub

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

NO_STAGE=	yes
.include <bsd.port.mk>
