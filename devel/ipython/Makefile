# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	ipython
PORTVERSION=	5.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Enhanced Interactive Python shell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>=0:misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}pickleshare>=0:databases/py-pickleshare \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=1.0.3:devel/py-prompt_toolkit \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}simplegeneric>0.8:devel/py-simplegeneric \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2:devel/py-traitlets

USES=		python
USE_PYTHON=	autoplist distutils
USE_GCC=	yes # To be removed - Needed as a work-around for numpy, see PR ports/188114
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.shutil_get_terminal_size>=0:devel/py-backports.shutil_get_terminal_size
.endif
.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathlib2>=0:devel/py-pathlib2
.endif

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

.include <bsd.port.post.mk>
