# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ninja-ide
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cross-platform integrated development environment (IDE)

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5,1:net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.8.5:www/py-qt4-webkit
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-declarative>=4.10.2:devel/py-qt4-declarative \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5,1:net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.8.5:www/py-qt4-webkit

USES=		python:2
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	ninja-ide

.include <bsd.port.mk>
