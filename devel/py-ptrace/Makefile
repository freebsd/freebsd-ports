# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptrace
PORTVERSION=	0.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ptrace-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python binding of ptrace

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distorm>0:${PORTSDIR}/devel/py-distorm

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog PKG-INFO README README.cptrace TODO
PORTEXAMPLES=	itrace.py simple_dbg.py

OPTIONS_DEFINE= DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

post-patch:
	${REINPLACE_CMD} -e 's|libdistorm64.so|${PYTHON_SITELIBDIR}/distorm3/libdistorm3.so|' \
		${WRKSRC}/ptrace/pydistorm.py

regression-test: extract
	@(cd ${WRKSRC} && ${PYTHON_CMD} test_doc.py)

.include <bsd.port.mk>
