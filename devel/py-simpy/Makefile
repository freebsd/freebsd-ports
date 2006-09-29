# ex:ts=8
# Ports collection makefile for:	py-simpy
# Date created:			Jun 29, 2004
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	simpy
PORTVERSION=	1.7.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimPy-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Simulation in Python

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/SimPyDocs && ${FIND} . | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
.endif
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/SimPyModels && ${FIND} . | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR})

.include <bsd.port.mk>
