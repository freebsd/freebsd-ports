# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hiplot
PORTVERSION=	0.1.3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High dimensional Interactive Plotting tool

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Compress>=0:www/py-flask-compress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.0.1:devel/ipython@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${MKDIR} ${WRKSRC}/requirements
	@${CP} ${FILESDIR}/dev.txt ${FILESDIR}/main.txt ${WRKSRC}/requirements

.include <bsd.port.mk>
