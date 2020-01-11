# $FreeBSD$

PORTNAME=		macs2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.2.6
CATEGORIES=		biology python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify transcription factor binding sites

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

USE_GITHUB=	yes
GH_ACCOUNT=	taoliu
GH_PROJECT=	MACS

post-stage:
	${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*/*.so

.include <bsd.port.mk>
