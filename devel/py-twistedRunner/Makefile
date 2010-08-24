# New ports collection makefile for:	py-twistedRunner
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedRunner
PORTVERSION=	10.1.0
CATEGORIES=	devel net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Runner/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedRunner-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Runner has process management, including an inetd replacement

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Runner

.include <bsd.port.mk>
