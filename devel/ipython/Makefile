# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	ipython
PORTVERSION=	3.2.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Enhanced Interactive Python shell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>=2:${PORTSDIR}/misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2:${PORTSDIR}/databases/py-sqlite3

USES=		python
USE_PYTHON=	autoplist distutils
USE_GCC=	yes # To be removed - Needed as a work-around for numpy, see PR ports/188114

OPTIONS_DEFINE=	X11 HTML_NOTEBOOK ZMQ EXAMPLES
OPTIONS_DEFAULT=X11 ZMQ

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	HTML_NOTEBOOK
.endif

HTML_NOTEBOOK_DESC=	HTML notebook support
ZMQ_DESC=		ZMQ support (parallel computing, qt console, notebook)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:${PORTSDIR}/textproc/py-pygments
.endif

.if ${PORT_OPTIONS:MHTML_NOTEBOOK}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=2.0:${PORTSDIR}/www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:${PORTSDIR}/devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}mistune>=0:${PORTSDIR}/textproc/py-mistune
.endif

.if ${PORT_OPTIONS:MZMQ} || ${PORT_OPTIONS:MHTML_NOTEBOOK}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.4:${PORTSDIR}/net/py-pyzmq
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif
	@${ECHO_CMD} "/EASY-INSTALL"	> ${WRKDIR}/ex.script
	@${ECHO_CMD} "a"		>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "import os"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "os.environ[\"LD_LIBRARY_PATH\"]=\"${_GCC_RUNTIME}\"" >> ${WRKDIR}/ex.script
	@${ECHO_CMD} "."		>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"		>> ${WRKDIR}/ex.script
	@for file in ${STAGEDIR}${PREFIX}/bin/*; do \
		ex $${file} < ${WRKDIR}/ex.script > /dev/null; \
	done

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == "3.1" || ${PYTHON_VER} == "3.2"
IGNORE=		only Python versions 2.7, 3.3 and 3.4 are supported
.endif

.include <bsd.port.post.mk>
