PORTNAME=	qudida
DISTVERSION=	0.0.4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QUick and DIrty Domain Adaptation
WWW=		https://github.com/arsenyinfo/qudida

LICENSE=	MIT

RUN_DEPENDS=	${PYNUMPY} \
		opencv>=4.0.1:graphics/opencv \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.19.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
