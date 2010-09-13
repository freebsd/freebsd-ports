# New ports collection makefile for:	py-InlineEgg
# Date created:		2009-12-22
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	InlineEgg
PORTVERSION=	1.08
CATEGORIES=	devel security python
MASTER_SITES=	http://oss.corest.com/repo/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Python module for writing inline assembler programs

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
PORTDOCS=	InlineEgg.html Changelog README
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA}  ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
