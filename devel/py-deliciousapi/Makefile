# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	deliciousapi
PORTVERSION=	1.6.7
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	DeliciousAPI-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Unofficial Python API for retrieving data from Delicious.com

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/BeautifulSoup.py:www/py-beautifulsoup32@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.7:devel/py-simplejson@${FLAVOR}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
