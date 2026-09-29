PORTNAME=	visidata
PORTVERSION=	3.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal interface for exploring and arranging tabular data
WWW=		https://www.visidata.org/ \
		https://github.com/saulpw/visidata

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.gpl3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}standard-mailcap>=0:mail/py-standard-mailcap@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
