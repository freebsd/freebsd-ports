PORTNAME=	libjitterentropy
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Hardware RNG based on CPU timing jitter
WWW=		https://www.chronox.de/jent.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.bsd

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	smuellerDD
GH_PROJECT=	jitterentropy-library
USE_LDCONFIG=	yes

INSTALL_TARGET=	install install-static

PLIST_SUB=	PORTVERSION=${PORTVERSION} PORTVERSION_MAJOR=${PORTVERSION:C/\..*//}

.include <bsd.port.mk>
