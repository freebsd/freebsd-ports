# New ports collection makefile for:	py-grouch
# Date created:		6 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grouch
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	http://www.mems-exchange.org/software/files/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Grouch-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system for describing and enforcing a Python object schema

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 220
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/compiler/__init__.py:${PORTSDIR}/lang/py-compiler
.endif

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGES LICENSE README
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile}.txt ${DOCSDIR}
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
