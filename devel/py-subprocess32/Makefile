# $FreeBSD$

PORTNAME=	subprocess32
DISTVERSION=	3.5.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Backport of the subprocess module from Python 3

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Python 2 only, following EOL of lang/python27
EXPIRATION_DATE=	2020-12-31

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_posixsubprocess32.so

.include <bsd.port.mk>
