# New ports collection makefile for:	py-twistedNames
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedNames
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	dns devel python
MASTER_SITES=	http://twistedmatrix.com/downloads/Names/0.1/ \
		http://tmrc.mit.edu/mirror/twisted/Names/0.2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedNames-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	A DNS protocol implementation with client and server

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedNames-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
