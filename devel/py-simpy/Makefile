# ex:ts=8
# Ports collection makefile for:	py-simpy
# Date created:			Jun 29, 2004
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	simpy
PORTVERSION=	1.8
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimPy-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Simulation in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

OPTIONS=	TKINTER		"Install py-tkinter for plot"      off
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.if !defined(NOPORTDOCS)
PORTDOCS=	*
DOCSDIR=	${TARGETDIR}/share/doc/py-${PORTNAME}
.endif
EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_TKINTER)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
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

.include <bsd.port.post.mk>
