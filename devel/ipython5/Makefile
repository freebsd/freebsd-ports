# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	ipython
PORTVERSION=	5.10.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	5

MAINTAINER=	python@FreeBSD.org
COMMENT=	Enhanced Interactive Python shell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>=0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pickleshare>=0:databases/py-pickleshare@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit1>=1.0.4<2.0.0:devel/py-prompt_toolkit1@${PY_FLAVOR} \
		${PY_PYGMENTS} \
		${PYTHON_PKGNAMEPREFIX}simplegeneric>0.8:devel/py-simplegeneric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2:devel/py-traitlets@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils
USE_GCC=	yes # To be removed - Needed as a work-around for numpy, see PR ports/188114

NO_ARCH=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

PORTSCOUT=	limit:^5\.

post-install:
	@${ECHO_CMD} "/EASY-INSTALL"	> ${WRKDIR}/ex.script
	@${ECHO_CMD} "a"		>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "import os"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "os.environ[\"LD_LIBRARY_PATH\"]=\"${_GCC_RUNTIME}\"" >> ${WRKDIR}/ex.script
	@${ECHO_CMD} "."		>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"		>> ${WRKDIR}/ex.script
	@for file in ${STAGEDIR}${PREFIX}/bin/*; do \
		ex $${file} < ${WRKDIR}/ex.script > /dev/null; \
	done

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
