PORTNAME=	dosage
DISTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Application to keep a local mirror of web comics
WWW=		https://dosage.rocks/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imagesize>0:graphics/py-imagesize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist noflavors

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cached-property>0:devel/py-cached-property@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
