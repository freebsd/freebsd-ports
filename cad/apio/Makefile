PORTNAME=	apio
DISTVERSION=	1.6.0
CATEGORIES=	cad python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source ecosystem for open FPGA boards
WWW=		https://github.com/FPGAwars/apio

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apollo-fpga>0:cad/py-apollo-fpga@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blackiceprog>0:cad/py-blackiceprog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debugpy>0:devel/py-debugpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}icefunprog>0:cad/py-icefunprog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}invoke>0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json5>0:devel/py-json5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		scons-${PY_FLAVOR}>0:devel/scons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>0:devel/py-semantic-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinyfpgab>0:cad/py-tinyfpgab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinyprog>0:cad/py-tinyprog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcdvcd>0:cad/py-vcdvcd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=2:devel/py-flit-core@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python shebangfix
USE_PYTHON=	autoplist noflavors pep517

SHEBANG_FILES=	apio/__main__.py
python_OLD_CMD=	venv/bin/python

NO_ARCH=	yes

.include <bsd.port.mk>
