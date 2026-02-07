PORTNAME=	pymaging-png
DISTVERSIONPREFIX=	g
DISTVERSION=	20130727
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	PNG support for pymaging
WWW=		https://pymaging.rtfd.org

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymaging>=g20130908:graphics/py-pymaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

USE_GITHUB=	yes
GH_ACCOUNT=	ojii
GH_TAGNAME=	83d85c4

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -E \
		-e "/^[[:blank:]]+version[[:blank:]]*=/s/__version__/${DISTVERSION}/" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
