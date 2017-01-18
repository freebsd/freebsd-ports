# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptrace
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ptrace-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python binding of ptrace

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distorm>0:devel/py-distorm

USES=		python
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	PKG-INFO README.rst
PORTEXAMPLES=	itrace.py simple_dbg.py

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

post-patch:
	${REINPLACE_CMD} -e 's|libdistorm64.so|${PYTHON_SITELIBDIR}/distorm3/libdistorm3.so|' \
		${WRKSRC}/ptrace/pydistorm.py

do-test: extract
	@(cd ${WRKSRC} && ${PYTHON_CMD} runtests.py)

.include <bsd.port.mk>
