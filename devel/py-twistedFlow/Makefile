# New ports collection makefile for:	py-twistedFlow
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedFlow
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://twistedmatrix.com/downloads/Flow/0.1/ \
		http://tmrc.mit.edu/mirror/twisted/Flow/0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedFlow-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Generator based asynchronous result flows

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedFlow-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

post-extract:
	# temporal hack to work with Twisted 2.4
	${ECHO_CMD} "from twisted.python import versions" > ${WRKSRC}/twisted/flow/_version.py
	${ECHO_CMD} "version = versions.Version(__name__[:__name__.rfind('.')], 0, 1, 0)" >> ${WRKSRC}/twisted/flow/_version.py

.include <bsd.port.mk>
