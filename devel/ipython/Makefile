# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	ipython
PORTVERSION=	3.2.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced Interactive Python shell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2:databases/py-sqlite3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>=2:misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2:databases/py-sqlite3

USES=		python
USE_PYTHON=	autoplist distutils
USE_GCC=	yes # To be removed - Needed as a work-around for numpy, see PR ports/188114
NO_ARCH=	yes

OPTIONS_DEFINE=	X11 HTML_NOTEBOOK ZMQ EXAMPLES
OPTIONS_DEFAULT=X11 ZMQ

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	HTML_NOTEBOOK
.endif

HTML_NOTEBOOK_DESC=	HTML notebook support
ZMQ_DESC=		ZMQ support (parallel computing, qt console, notebook)

X11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui \
			${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:graphics/py-qt4-svg \
			${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments

HTML_NOTEBOOK_RUN_DEPENDS=\
			${PYTHON_PKGNAMEPREFIX}tornado>=2.0:www/py-tornado \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2 \
			${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema \
			${PYTHON_PKGNAMEPREFIX}mistune>=0:textproc/py-mistune \
			${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.4:net/py-pyzmq

ZMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.4:net/py-pyzmq

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
