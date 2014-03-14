# Created by: Nicola Vitale	<nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GChartWrapper
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		LOCAL/nivit/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}.zip
.if !defined(NOPORTDOCS) || !defined(NOPORTEXAMPLES)
DISTFILES+=	${PORTNAME}-extras-${PORTVERSION}.zip
.endif

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python Google Chart Wrapper

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_2:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USES=		zip
NO_STAGE=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PROJECTHOST=	google-chartwrapper

.if !defined(NOPORTDOCS)
post-extract:
	@cd ${WRKDIR} && ${RM} -R doc/.svn && ${RM} -R demo/.svn
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} && cd ${WRKDIR}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR} && cd ${WRKDIR}/demo && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
