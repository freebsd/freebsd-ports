PORTNAME=	erfa
DISTVERSION=	2.0.1
CATEGORIES=	astro
MASTER_SITES=	https://github.com/liberfa/erfa/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Essential Routines for Fundamental Astronomy
WWW=		https://github.com/liberfa/erfa

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
