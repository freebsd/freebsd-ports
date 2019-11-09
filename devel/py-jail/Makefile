# $FreeBSD$

PORTNAME=		jail
PORTVERSION=	0.0.9
CATEGORIES=		devel python sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		stefan@gronke.net
COMMENT=		Native Python wrapper for FreeBSD jails using libc

LICENSE=		BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freebsd-sysctl>0:devel/py-freebsd-sysctl@${PY_FLAVOR}

USES=			python:3.6+

USE_GITHUB=		yes
GH_ACCOUNT=		gronke
GH_PROJECT=		py-jail

NO_ARCH=		yes
USE_PYTHON=		distutils autoplist

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
