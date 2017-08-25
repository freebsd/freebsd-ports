# Created by: Evan Sarmiento <bsdports@wayfair.com>
# $FreeBSD$

PORTNAME=	carbon
PORTVERSION=	0.9.15
PORTREVISION=	2
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Backend storage application for graphite

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}txamqp>=0.3:net/py-txamqp \
		${PYTHON_PKGNAMEPREFIX}whisper>=0.9.10:databases/py-whisper \
		${PYTHON_PKGNAMEPREFIX}django18>=1.4:www/py-django18

NO_ARCH=	yes
USE_PYTHON=	distutils
USES=		python:2.7
USE_RC_SUBR=	carbon
USE_GITHUB=	yes
GH_ACCOUNT=	graphite-project

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/examples/init.d
	${RMDIR} ${STAGEDIR}${PREFIX}/examples

.include <bsd.port.mk>
