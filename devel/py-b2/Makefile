PORTNAME=	b2
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Command Line Interface for Backblaze's B2 storage service
WWW=		https://www.backblaze.com/b2/docs/quick_command_line.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9.0:devel/py-tabulate@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=3.5.2:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arrow>=1.0.2:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}b2sdk>=2.9.4:devel/py-b2sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.18.1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phx-class-registry>=4.0:devel/py-phx-class-registry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=3.11.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rst2ansi>=0.1.5:textproc/py-rst2ansi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9.0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.65.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent optsuffix pep517

CONFLICTS_INSTALL=	boost_build

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Backblaze
GH_PROJECT=	B2_Command_Line_Tool

MAKE_ENV=	PDM_BUILD_SCM_VERSION=${DISTVERSION}

.include <bsd.port.mk>
