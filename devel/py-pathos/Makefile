# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pathos
PORTVERSION=	0.2.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parallel graph management and execution in heterogeneous computing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dill>=0.3.4:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multiprocess>=0.70.12:devel/py-multiprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pox>=0.3.0:devel/py-pox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ppft>=1.6.6.4:devel/py-ppft@${PY_FLAVOR}

USES=		python:3.7+ zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
