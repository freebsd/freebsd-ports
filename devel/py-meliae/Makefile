# $FreeBSD$

PORTNAME=	meliae
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://launchpadlibrarian.net/74803944/ \
		LOCAL/sbz
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python Memory Usage Analyzer

LICENSE=	GPLv3

BUILD_DEPENDS=	cython>0:lang/cython

USES=		python:2
USE_PYTHON=	distutils autoplist

regression-test: extract
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
