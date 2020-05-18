# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyinstaller
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyInstaller-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Program to create standalone executables from Python scripts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BROKEN_FreeBSD_12_powerpc64=	fails to compile: /usr/include/machine/ieeefp.h:36: expected '=', ',', ';', 'asm' or '__attribute__' before 'extern'
BROKEN_FreeBSD_13_powerpc64=	fails to compile: /usr/include/machine/ieeefp.h:35:1: error: unknown type name '__BEGIN_DECLS'

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}altgraph>0:math/py-altgraph@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

EXTRACT_AFTER_ARGS=	--exclude doc/source --no-same-owner --no-same-permissions
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*.txt

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx18>0:textproc/py-sphinx18@${PY_FLAVOR}
DOCS_MAKE_ARGS=		SPHINXBUILD=sphinx-build-${PYTHON_VER}
DOCS_USES=		gmake
MANPAGES_BUILD_DEPENDS=	${DOCS_BUILD_DEPENDS}
MANPAGES_MAKE_ARGS=	${DOCS_MAKE_ARGS}
MANPAGES_USES=		gmake

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dis3>0:devel/py-dis3@${PY_FLAVOR}
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dis3>0:devel/py-dis3@${PY_FLAVOR}
.endif
.endif

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
	( cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} man ${MAKE_ARGS})
	( cd ${WRKSRC}/doc/_build/man ; ${INSTALL_MAN} pyi-makespec.1 pyinstaller.1 \
		${STAGEDIR}${PREFIX}/share/man/man1 )

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} text ${MAKE_ARGS})
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/_build/text/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
