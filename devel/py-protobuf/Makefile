# Created by: vanilla@
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google protobuf Python Client Library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-apputils>=0:${PORTSDIR}/devel/py-google-apputils \
		protoc:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-apputils>=0:${PORTSDIR}/devel/py-google-apputils

USE_PYTHON=	autoplist distutils
USES=		python tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/python

GH_ACCOUNT=	google
USE_GITHUB=	yes

post-patch:
	@${MKDIR} ${WRKSRC}/google/protobuf/compiler/

regression-test test: build
	cd ${WRKSRC}/ && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
