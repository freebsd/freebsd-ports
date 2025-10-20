PORTNAME=	sip
PORTVERSION=	${SIP_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_SIP}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/Python-SIP/sip/commit/
PATCHFILES+=	b6a7ec2453899b878ffe0b2b5b1f642a0992aa6d.patch:-p1 # Fix build regession for devel/py-qt5-pyqt

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator
WWW=		https://github.com/Python-SIP/sip

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_SETUPTOOLS} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python pyqt:sip
USE_PYTHON=	autoplist concurrent pep517
USE_PYQT=	#

NO_ARCH=	yes

.include <bsd.port.mk>
