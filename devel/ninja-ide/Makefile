# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ninja-ide
DISTVERSION=	2.2-dev
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cross-platform integrated development environment (IDE)

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5,1:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.8.5:${PORTSDIR}/www/py-qt4-webkit
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5,1:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.8.5:${PORTSDIR}/www/py-qt4-webkit

#PYDISTUTILS_PKGNAME=	${PORTNAME:tu:S,-,_,}
PYDISTUTILS_PKGNAME=	${PORTNAME:U:S,-,_,}
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}_dev

USE_GITHUB=	yes
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	ninja-ide
GH_COMMIT=	5ab6252
GH_TAGNAME=	v${PORTVERSION:R}

.include <bsd.port.mk>
