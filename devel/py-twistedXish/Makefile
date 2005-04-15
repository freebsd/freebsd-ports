# New ports collection makefile for:	py-twistedXish
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedXish
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://twistedmatrix.com/downloads/Xish/0.1/ \
		http://tmrc.mit.edu/mirror/twisted/Xish/0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedXish-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Twisted Xish is XML-ish

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedXish-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
