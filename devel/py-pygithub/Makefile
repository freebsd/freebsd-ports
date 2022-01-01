# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	pygithub
PORTVERSION=	1.55
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyGithub-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python library implementing the full GitHub API v3

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.14.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.4.0:security/py-pynacl@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
