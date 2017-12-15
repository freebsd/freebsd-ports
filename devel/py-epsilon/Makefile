# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	epsilon
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Epsilon-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of Python utility modules used by DivMod projects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

CONFLICTS_INSTALL=	brlcad-[0-9]*	# bin/benchmark

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
