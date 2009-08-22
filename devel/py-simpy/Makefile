# ex:ts=8
# Ports collection makefile for:	py-simpy
# Date created:			Jun 29, 2004
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	simpy
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		SF/${PORTNAME}/${PORTNAME}/SimPy-${PORTVERSION}

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimPy-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Simulation in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	SimPy

OPTIONS=	TKINTER		"Install py-tkinter for plot"      off
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>

.if defined(WITH_TKINTER)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/SimPyDocs && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/SimPyModels && ${FIND} . | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
