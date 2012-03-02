# New ports collection makefile for:	py-foolscap 
# Date created:		2 March 2012
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	foolscap
PORTVERSION=	0.6.3
CATEGORIES=	devel python
MASTER_SITES=	http://foolscap.lothar.com/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An RPC protocol for Twisted Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
