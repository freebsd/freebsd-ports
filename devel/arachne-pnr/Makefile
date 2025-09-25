PORTNAME=	arachne-pnr
PORTVERSION=	g20181021
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Place and route tool for FPGAs
WWW=		https://github.com/cseed/arachne-pnr

DEPRECATED=	Superseded by devel/nextpnr
EXPIRATION_DATE=2025-12-31

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	icestorm>=g0:devel/icestorm

USES=		compiler:c++11-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	cseed
GH_TAGNAME=	840bdfdeb38809f9f6af4d89dd7b22959b176fdd

CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-Wno-error=pessimizing-move

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/arachne-pnr

.include <bsd.port.mk>
