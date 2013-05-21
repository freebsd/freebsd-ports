# Created by: ijliao
# $FreeBSD$

PORTNAME=	simpy
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		SF/${PORTNAME}/${PORTNAME}/SimPy-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimPy-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Simulation in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	SimPy

OPTIONS_DEFINE=	TKINTER
TKINTER_DESC=	py-tkinter for plot

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTKINTER}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
