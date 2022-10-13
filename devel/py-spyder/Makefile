PORTNAME=	spyder
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.7
PORTREVISION=	14
CATEGORIES=	devel science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific PYthon Development EnviRonment, an alternative to IDLE
WWW=		https://www.spyder-ide.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.3.1:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>=0.3.1:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.9.0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=4.0:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8>=0.6:devel/pep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.3:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>0:textproc/py-numpydoc@${PY_FLAVOR} \

		${PYTHON_PKGNAMEPREFIX}parso>=0.7.0:textproc/py-parso@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}pexpect>=4.4.0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pickleshare>=0.4:databases/py-pickleshare@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.3:sysutils/py-psutil@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR}
		pylint${PYTHON_PKGNAMESUFFIX}>=2.5.0:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylint-venv>=2.1.1:devel/py-pylint-venv@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}python-lsp-server>=1.5.0:textproc/py-python-lsp-server@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}pyxdg>=0.26:devel/py-pyxdg@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}pyzmq>=22.1.0:net/py-pyzmq@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}QDarkStyle>=3.0.2:textproc/py-QDarkStyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qstylizer>=0.1.10:devel/py-qstylizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtAwesome>=1.0.2:x11-fonts/py-QtAwesome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qtconsole>=5.3.2:devel/py-qtconsole@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.1.0:py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>=0.9.7:devel/py-rtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spyder-kernels>=2.3.3:devel/py-spyder-kernels@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}textdistance>=4.2.0:textproc/py-textdistance@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}three-merge>=0.1.1:textproc/py-three-merge@${PY_FLAVOR}
		${PYTHON_PKGNAMEPREFIX}watchdog>=0.10.3:devel/py-watchdog@${PY_FLAVOR}

install_requires = [
    'applaunchservices>=0.3.0;platform_system=="Darwin"',
    'atomicwrites>=1.2.0',
    'chardet>=2.0.0',
    'cloudpickle>=0.5.0',
    'cookiecutter>=1.6.0',
    'diff-match-patch>=20181111',
    'intervaltree>=3.0.2',
    'ipython>=7.31.1,<8.0.0',
    'jedi>=0.17.2,<0.19.0',
    'jellyfish>=0.7',
    'jsonschema>=3.2.0',
    'keyring>=17.0.0',
    'nbconvert>=4.0',
    'numpydoc>=0.6.0',
    # Required to get SSH connections to remote kernels
    'paramiko>=2.4.0;platform_system=="Windows"',
    'parso>=0.7.0,<0.9.0',
    'pexpect>=4.4.0',
    'pickleshare>=0.4',
    'psutil>=5.3',
    'pygments>=2.0',
    'pylint>=2.5.0,<3.0',
    'pylint-venv>=2.1.1',
    'python-lsp-black>=1.2.0',
    'pyls-spyder>=0.4.0',
    'pyqt5<5.16',
    'pyqtwebengine<5.16',
    'python-lsp-server[all]>=1.5.0,<1.6.0',
    'pyxdg>=0.26;platform_system=="Linux"',
    'pyzmq>=22.1.0',
    'qdarkstyle>=3.0.2,<3.1.0',
    'qstylizer>=0.1.10',
    'qtawesome>=1.0.2',
    'qtconsole>=5.3.2,<5.4.0',
    'qtpy>=2.1.0',
    'rtree>=0.9.7',
    'setuptools>=49.6.0',
    'sphinx>=0.6.6',
    'spyder-kernels>=2.3.3,<2.4.0',
    'textdistance>=4.2.0',
    'three-merge>=0.1.1',
    'watchdog>=0.10.3'
]

USES=		desktop-file-utils python:3.7+ pyqt:5
USE_GITHUB=	yes
GH_ACCOUNT=	spyder-ide
USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	pyqt5 sip
NO_ARCH=	yes

DOCSDIR=	${PYTHON_SITELIBDIR}/spyder

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	RECOMMENDED OPTIONAL
OPTIONS_GROUP_RECOMMENDED=	IPYTHON MATPLOT NUMPY PSUTIL PYFLAKES ROPE SCIPY SPHINX
OPTIONS_GROUP_OPTIONAL=	PANDAS PYGMENTS SYMPY
OPTIONS_DEFAULT=	IPYTHON MATPLOT NUMPY PSUTIL PYFLAKES ROPE SCIPY SPHINX

IPYTHON_DESC=	IPython Console integration
MATPLOT_DESC=	Interactive data plotting in the consoles
NUMPY_DESC=	N-dimensional arrays
PANDAS_DESC=	View and edit DataFrames and Series in the Variable Explorer
PSUTIL_DESC=	CPU and memory usage info in the status bar
PYFLAKES_DESC=	Real-time code analysis on the Editor
PYGMENTS_DESC=	Syntax highlighting for Matlab, Julia and other file types
ROPE_DESC=	Editor's code completion, go-to-definition and help
SCIPY_DESC=	Signal/image processing
SPHINX_DESC=	Rich text help on the Object Inspector
SYMPY_DESC=	Symbolic mathematics in the IPython Console

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
IPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=6.0:devel/ipython@${PY_FLAVOR} \
MATPLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.0:math/py-matplotlib@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYNUMPY}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.13.1:math/py-pandas@${PY_FLAVOR}
PYFLAKES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyflakes>=0.5:devel/py-pyflakes@${PY_FLAVOR}
ROPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rope>=0.9.2:devel/py-rope@${PY_FLAVOR}
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
SPHINX_RUN_DEPENDS=	${DOCS_BUILD_DEPENDS}
SYMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=0.7.3:math/py-sympy@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e "s|'linux'|'${OPSYS:tl}'|g" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|cmdclass=CMDCLASS||g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
