# New ports collection makefile for:	gchartwrapper
# Date created:		2009-01-09
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GChartWrapper
PORTVERSION=	0.8
PORTREVISION=	0
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		LOCAL/nivit/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
.if !defined(NOPORTDOCS) || !defined(NOPORTEXAMPLES)
DISTFILES+=	${PORTNAME}-extras-${PORTVERSION}.tar.gz
.endif

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python Google Chart Wrapper

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_2:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PROJECTHOST=	google-chartwrapper

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} && cd ${WRKDIR}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR} && cd ${WRKDIR}/templating && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
