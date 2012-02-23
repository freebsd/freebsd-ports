# New ports collection makefile for:	py-bitarray
# Date created:		2010-12-16
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bitarray
PORTVERSION=	0.7.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Efficient arrays of booleans

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	AUTHORS CHANGE_LOG LICENSE README.rst

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

regression-test:
	@(cd ${WRKSRC}/${PORTNAME}; ${PYTHON_CMD} -c "import ${PORTNAME}; ${PORTNAME}.test()")

.include <bsd.port.mk>
