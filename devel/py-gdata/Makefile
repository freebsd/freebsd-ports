# New ports collection makefile for:	py-gdata
# Date created:		Mar. 28, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	gdata
PORTVERSION=	2.0.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	GData Python Client Library

PROJECTHOST=	gdata-python-client
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
.endif

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
