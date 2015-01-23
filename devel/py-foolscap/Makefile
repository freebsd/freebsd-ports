# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foolscap
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://foolscap.lothar.com/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	RPC protocol for Twisted Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0.13:${PORTSDIR}/security/py-openssl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python twisted
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
