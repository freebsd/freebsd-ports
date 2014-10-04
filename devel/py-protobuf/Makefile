# Created by: vanilla@
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.6.0
CATEGORIES=	devel python
MASTER_SITES=	https://protobuf.googlecode.com/svn/rc/ \
		LOCAL/sunpoet
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

post-patch:
	@${MKDIR} ${WRKSRC}/google/protobuf/compiler/

regression-test test: build
	cd ${WRKSRC}/ && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
