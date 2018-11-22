# $FreeBSD$

PORTNAME=	plasma
DISTVERSION=	g20171121
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Interactive disassembler for x86/ARM/MIPS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		binutils>=2:devel/binutils \
		capstone>=3:devel/capstone3
RUN_DEPENDS=	binutils>=2:devel/binutils \
		${PYTHON_PKGNAMEPREFIX}capstone>=3:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystone-engine>=:devel/py-keystone-engine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools@${PY_FLAVOR}

USES=		python:3.4+ shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	plasma-disassembler
GH_PROJECT=	plasma
GH_TAGNAME=	8ec3bb7

USE_PYTHON=	distutils noflavors autoplist
SHEBANG_FILES=	tests/analyzer/run.sh
SHEBANG_GLOB=	*.py

OPTIONS_DEFINE=		MEMMAP
OPTIONS_DEFAULT=	MEMMAP
MEMMAP_DESC=	View memory maps (pulls in QT4)
MEMMAP_USES=	pyqt:4
MEMMAP_USE=	PYQT=gui_run

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
