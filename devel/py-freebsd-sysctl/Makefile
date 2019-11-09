# $FreeBSD$

PORTNAME=		freebsd-sysctl
PORTVERSION=	0.0.7
CATEGORIES=		devel python sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		stefan@gronke.net
COMMENT=		Native Python wrapper for FreeBSD sysctls using libc

LICENSE=		BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=			python:3.6+

USE_GITHUB=		yes
GH_ACCOUNT=		gronke
GH_PROJECT=		py-freebsd_sysctl

NO_ARCH=		yes
USE_PYTHON=		distutils autoplist

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
