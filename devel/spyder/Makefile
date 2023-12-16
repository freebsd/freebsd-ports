PORTNAME=	spyder
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.5
DISTREVISION=	3
CATEGORIES=	devel science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific PYthon Development EnviRonment, an alternative to IDLE
WWW=		https://www.spyder-ide.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}atomicwrites>=1.2.0:devel/py-atomicwrites@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.0.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>=0.5.0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cookiecutter>=1.6.0:devel/py-cookiecutter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diff-match-patch>=20181111:textproc/py-diff-match-patch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=3.0.2:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.31.1:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.17.2:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jellyfish>=0.7:devel/py-jellyfish@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.2.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=17.0.0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=4.0:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=0.6.0:textproc/py-numpydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parso>=0.7.0:textproc/py-parso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=4.4.0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pickleshare>=0.4:databases/py-pickleshare@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.3:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=2.5.0:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylint-venv>=3.0.2:devel/py-pylint-venv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-lsp-black>=1.2.0:textproc/py-python-lsp-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyls-spyder>=0.4.0:textproc/py-pyls-spyder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt5-webengine>0:www/py-qt5-webengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-lsp-server>=1.7.4:textproc/py-python-lsp-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.26:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=22.1.0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QDarkStyle>=3.0.2:textproc/py-QDarkStyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qstylizer>=0.2.2:devel/py-qstylizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtAwesome>=1.2.1:x11-fonts/py-QtAwesome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qtconsole>=5.4.0:devel/py-qtconsole@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.1.0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>=0.9.7:devel/py-rtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0.6.6:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spyder-kernels>=2.4.4:devel/py-spyder-kernels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textdistance>=4.2.0:textproc/py-textdistance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}three-merge>=0.1.1:textproc/py-three-merge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=0.10.3:devel/py-watchdog@${PY_FLAVOR}

USES=		desktop-file-utils python pyqt:5
USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	pyqt5 sip

USE_GITHUB=	yes
GH_ACCOUNT=	spyder-ide

NO_ARCH=	yes

DOCSDIR=	${PYTHON_SITELIBDIR}/spyder

post-extract: # remove bundled dependencies
	@${RM} -r ${WRKSRC}/external-deps/*

.include <bsd.port.mk>
