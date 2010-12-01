# New ports collection makefile for:	py-bitstring
# Date created:		2010-11-29
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bitstring
PORTVERSION=	2.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Simple construction, analysis and modification of binary data

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes
USE_ZIP=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}.py \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}.pyc \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}.pyo

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	PKG-INFO README.txt release_notes.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

regression-test:
	@(cd ${WRKSRC}/test && ${PYTHON_CMD} test_${PORTNAME}.py)

.include <bsd.port.mk>
