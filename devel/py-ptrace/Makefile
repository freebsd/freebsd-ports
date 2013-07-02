# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptrace
PORTVERSION=	0.6.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ptrace-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python binding of ptrace

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distorm>0:${PORTSDIR}/devel/py-distorm

USE_PYTHON=	2.7+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_ptrace

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${DOCSDIR:C/doc/examples/}

PORTSDOCS=	AUTHORS ChangeLog PKG-INFO README README.cptrace TODO

ONLY_FOR_ARCHS=	i386

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|libdistorm64.so|${PYTHON_SITELIBDIR}/distorm3/libdistorm3.so|' \
		${WRKSRC}/ptrace/pydistorm.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTSDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

regression-test: extract
	@(cd ${WRKSRC} && ${PYTHON_CMD} test_doc.py)

.include <bsd.port.mk>
