# Created by: vanilla@
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.5.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google protobuf Python Client Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../COPYING.txt

BUILD_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/python
PROJECTHOST=	protobuf

USES=		python tar:bzip2
USE_PYTHON=	autoplist distutils

pre-build:
	@${MKDIR} ${WRKSRC}/google/protobuf/compiler

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
