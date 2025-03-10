PORTNAME=	PyQt-builder
PORTVERSION=	${PYQTBUILDER_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQTBUILDER}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYQTBUILDER_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The PEP 517 compliant PyQt build system
WWW=		https://github.com/Python-PyQt/PyQt-builder

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python pyqt:6
USE_PYQT=	sip
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
