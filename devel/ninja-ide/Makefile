# New ports collection makefile for:	ninja-ide
# Date created:		2011-12-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ninja-ide
DISTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A cross-platform integrated development environment (IDE)

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5,1:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.8.5:${PORTSDIR}/www/py-qt4-webkit
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5,1:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.8.5:${PORTSDIR}/www/py-qt4-webkit

#PYDISTUTILS_PKGNAME=	${PORTNAME:tu:S,-,_,}
PYDISTUTILS_PKGNAME=	${PORTNAME:U:S,-,_,}

USE_GITHUB=	yes
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	ninja-ide
GH_COMMIT=	c42161b
GH_TAGNAME=	v${PORTVERSION}

.include <bsd.port.mk>
