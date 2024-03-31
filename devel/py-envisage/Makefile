PORTNAME=	envisage
PORTVERSION=	7.0.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enthought extensible application framework
WWW=		https://docs.enthought.com/envisage/ \
		https://github.com/enthought/envisage

LICENSE=	BSD3CLAUSE CC-BY-SA-1.0 CC-BY-SA-2.0 CC-BY-SA-2.5 CC-BY-SA-3.0 LGPL20 PSFL 
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL20=	${WRKSRC}/image_LICENSE_CP.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apptools>=0:devel/py-apptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyface>=0:devel/py-pyface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>=6.2:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitsui>=0:graphics/py-traitsui@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.1.0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
