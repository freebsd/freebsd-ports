PORTNAME=	gf2 # name of the executable that is built, while the repo is called gf
DISTVERSION=	g20250204
CATEGORIES=	devel

MAINTAINER=	me@pacopascal.com
COMMENT=	Graphical frontend for GDB
WWW=		https://github.com/nakst/gf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/bin/gdb:devel/gdb

USES=		xorg
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	nakst
GH_PROJECT=	gf
GH_TAGNAME=	9c16864

PLIST_FILES=	bin/gf2

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build_freebsd.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
