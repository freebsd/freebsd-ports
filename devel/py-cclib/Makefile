# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	cclib
PORTVERSION=	1.5.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Parsers And Algorithms For Computational Chemistry

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USE_GITHUB=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
