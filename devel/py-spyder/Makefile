# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	spyder
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.7
PORTREVISION=	1
CATEGORIES=	devel science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Scientific PYthon Development EnviRonment, an alternative to IDLE

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}QtAwesome>0:x11-fonts/py-QtAwesome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.3.1:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>=0.3.1:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.9.0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=4.0:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8>=0.6:devel/pep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.3:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qtconsole>=4.3.0:devel/py-qtconsole@${PY_FLAVOR}

USES=		desktop-file-utils python:3.4+ pyqt:5
USE_GITHUB=	yes
GH_ACCOUNT=	spyder-ide
USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	core_run gui_run network_run sip_run svg_run webkit_run webkitwidgets_run
NO_ARCH=	yes

DOCSDIR=	${PYTHON_SITELIBDIR}/spyder

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	RECOMMENDED OPTIONAL
OPTIONS_GROUP_RECOMMENDED=	IPYTHON MATPLOT NUMPY PSUTIL PYFLAKES ROPE SCIPY SPHINX
OPTIONS_GROUP_OPTIONAL=	PANDAS PYGMENTS PYLINT SYMPY
OPTIONS_DEFAULT=	IPYTHON MATPLOT NUMPY PSUTIL PYFLAKES ROPE SCIPY SPHINX

IPYTHON_DESC=	IPython Console integration
MATPLOT_DESC=	Interactive data plotting in the consoles
NUMPY_DESC=	N-dimensional arrays
PANDAS_DESC=	View and edit DataFrames and Series in the Variable Explorer
PSUTIL_DESC=	CPU and memory usage info in the status bar
PYFLAKES_DESC=	Real-time code analysis on the Editor
PYGMENTS_DESC=	Syntax highlighting for Matlab, Julia and other file types
PYLINT_DESC=	Static code analysis
ROPE_DESC=	Editor's code completion, go-to-definition and help
SCIPY_DESC=	Signal/image processing
SPHINX_DESC=	Rich text help on the Object Inspector
SYMPY_DESC=	Symbolic mathematics in the IPython Console

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0.6:textproc/py-sphinx@${PY_FLAVOR}
IPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=1.0:devel/ipython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.11:net/py-pyzmq@${PY_FLAVOR}
MATPLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.0:math/py-matplotlib@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYNUMPY}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.13.1:math/py-pandas@${PY_FLAVOR}
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0.3:sysutils/py-psutil@${PY_FLAVOR}
PYFLAKES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyflakes>=0.5:devel/py-pyflakes@${PY_FLAVOR}
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR}
PYLINT_RUN_DEPENDS=	pylint${PYTHON_PKGNAMESUFFIX}>=0.25:devel/pylint@${PY_FLAVOR}
ROPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rope>=0.9.2:devel/py-rope@${PY_FLAVOR}
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
SPHINX_RUN_DEPENDS=	${DOCS_BUILD_DEPENDS}
SYMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=0.7.3:math/py-sympy@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e "s|'linux'|'${OPSYS:tl}'|g" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|cmdclass=CMDCLASS||g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
