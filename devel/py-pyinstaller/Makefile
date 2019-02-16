# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyinstaller
PORTVERSION=	3.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyInstaller-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Program to create standalone executables from Python scripts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dis3>0:devel/py-dis3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}altgraph>0:math/py-altgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}macholib>=1.8:devel/py-macholib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=2017.8.1:devel/py-pefile@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

EXTRACT_AFTER_ARGS=	--exclude doc/source --no-same-owner --no-same-permissions
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*.txt

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dis3>0:devel/py-dis3@${PY_FLAVOR}
DOCS_MAKE_ARGS=		SPHINXBUILD=sphinx-build-${PYTHON_VER}
DOCS_USES=		gmake
MANPAGES_BUILD_DEPENDS=	${DOCS_BUILD_DEPENDS}
MANPAGES_MAKE_ARGS=	${DOCS_MAKE_ARGS}
MANPAGES_USES=		gmake

post-patch:
	@${REINPLACE_CMD} -e '/install_requires/s,distribute,setuptools,' \
		${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e '/\/sbin\/ldconfig/s,-p,-r,' \
		${WRKSRC}/PyInstaller/depend/utils.py
	${INSTALL_DATA} ${WRKSRC}/PyInstaller/utils/cliutils/makespec.py ${WRKSRC}/makespec.py

pre-build:
	cd ${WRKSRC}/bootloader && \
		${PYTHON_CMD} waf all

do-install-MANPAGES-on:
	@${MKDIR} ${STAGEDIR}${MANDIRS}/man1
	( cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} man ${MAKE_ARGS})
	( cd ${WRKSRC}/doc/_build/man ; ${INSTALL_MAN} pyi-makespec.1 pyinstaller.1 \
		${STAGEDIR}${MANDIRS}/man1 )

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} text ${MAKE_ARGS})
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/_build/text/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
