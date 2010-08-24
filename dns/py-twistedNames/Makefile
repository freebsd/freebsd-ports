# New ports collection makefile for:	py-twistedNames
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedNames
PORTVERSION=	10.1.0
CATEGORIES=	dns devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Names/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedNames-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	A DNS protocol implementation with client and server

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Names

.include <bsd.port.mk>
