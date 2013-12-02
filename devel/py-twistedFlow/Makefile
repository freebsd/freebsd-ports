# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedFlow
PORTVERSION=	8.2.0
CATEGORIES=	devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Flow/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedFlow-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Generator based asynchronous result flows

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedFlow-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Flow

.include <bsd.port.mk>
