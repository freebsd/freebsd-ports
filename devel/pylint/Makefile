# New ports collection makefile for:	pylint
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pylint
PORTVERSION=	0.25.0
CATEGORIES=	devel python
MASTER_SITES=	LOGILAB
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/logilab/astng/__init__.py:${PORTSDIR}/devel/py-astng

MAKE_ENV=	NO_SETUPTOOLS=1
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

OPTIONS=	GUI	"Include Tkinter support for pylint-gui"	Off

.include <bsd.port.pre.mk>

post-extract:
	${RM} -fr ${WRKSRC}/test

.if defined(WITH_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

.include <bsd.port.post.mk>
