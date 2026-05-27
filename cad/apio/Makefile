PORTNAME=	apio
DISTVERSION=	1.4.2
CATEGORIES=	cad python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source ecosystem for open FPGA boards
WWW=		https://github.com/FPGAwars/apio/wiki

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debugpy>0:devel/py-debugpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}invoke>0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		scons-${PY_FLAVOR}>0:devel/scons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>0:devel/py-semantic-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=2:devel/py-flit-core@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python shebangfix
USE_PYTHON=	noflavors pep517 concurrent autoplist

SHEBANG_FILES=	apio/common/proto/update-protos.sh

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!venv/bin/python|#!${PYTHON_CMD}|' ${WRKSRC}/apio/__main__.py
	@${RM} ${WRKSRC}/apio/__main__.py.bak

.include <bsd.port.mk>
