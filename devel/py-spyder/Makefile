# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	spyder
PORTVERSION=	2.3.7
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scientific PYthon Development EnviRonment, an alternative to IDLE

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui@${FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:graphics/py-qt4-svg@${FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt4/QtWebKit.so:www/py-qt4-webkit@${FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:net/py-qt4-network@${FLAVOR}

USES=		desktop-file-utils python
USE_PYTHON=	autoplist distutils
MAKE_ENV=	USE_SETUPTOOLS=1

USE_GITHUB=	yes
GH_ACCOUNT=	spyder-ide

DOCSDIR=	${PYTHON_SITELIBDIR}/spyderlib
PORTDOCS=	doc

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	RECOMMENDED OPTIONAL
OPTIONS_GROUP_RECOMMENDED=	IPYTHON MATPLOT NUMPY PSUTIL PYFLAKES ROPE SCIPY SPHINX
OPTIONS_GROUP_OPTIONAL=	JEDI PANDAS PEP8 PYGMENTS PYLINT SYMPY

IPYTHON_DESC=	IPython Console integration
JEDI_DESC=	(Experimental) Editor's code completion, go-to-definition and help
MATPLOT_DESC=	Interactive data plotting in the consoles
NUMPY_DESC=	N-dimensional arrays
PANDAS_DESC=	View and edit DataFrames and Series in the Variable Explorer
PEP8_DESC=	Real-time code style analysis on the Editor
PSUTIL_DESC=	CPU and memory usage info in the status bar
PYFLAKES_DESC=	Real-time code analysis on the Editor
PYGMENTS_DESC=	Syntax highlighting for Matlab, Julia and other file types
PYLINT_DESC=	Static code analysis
ROPE_DESC=	Editor's code completion, go-to-definition and help
SCIPY_DESC=	Signal/image processing
SPHINX_DESC=	Rich text help on the Object Inspector
SYMPY_DESC=	Symbolic mathematics in the IPython Console

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0.6:textproc/py-sphinx@${FLAVOR}
IPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=1.0:devel/ipython@${FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.11:net/py-pyzmq@${FLAVOR}
JEDI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jedi>=0.8.1:devel/py-jedi@${FLAVOR}
MATPLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.0:math/py-matplotlib@${FLAVOR}
NUMPY_RUN_DEPENDS=	${PYNUMPY}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.13.1:math/py-pandas@${FLAVOR}
PEP8_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pep8>=0.6:devel/pep8
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0.3:sysutils/py-psutil@${FLAVOR}
PYFLAKES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyflakes>=0.5:devel/py-pyflakes@${FLAVOR}
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${FLAVOR}
PYLINT_RUN_DEPENDS=	pylint${PYTHON_PKGNAMESUFFIX}>=0.25:devel/pylint@${FLAVOR}
ROPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rope>=0.9.2:devel/py-rope@${FLAVOR}
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR}
SPHINX_RUN_DEPENDS=	${DOCS_BUILD_DEPENDS}
SYMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=0.7.3:math/py-sympy@${FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e "s|'linux'|'${OPSYS:tl}'|" \
		${WRKSRC}/setup.py \
		${WRKSRC}/spyderlib/spyder.py

.include <bsd.port.mk>
