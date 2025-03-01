PORTNAME=	gf2 # name of the executable that is built, while the repo is called gf
DISTVERSION=	g20250204
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	me@pacopascal.com
COMMENT=	Graphical frontend for GDB
WWW=		https://github.com/nakst/gf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/bin/gdb:devel/gdb

USES=		localbase:ldflags xorg
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	nakst
GH_PROJECT=	gf
GH_TAGNAME=	9c16864

CXXFLAGS+=	-DUI_FREETYPE -I${LOCALBASE}/include/freetype2 \
		-Wall -Wextra -Wno-unused-parameter -Wno-unused-result \
		-Wno-missing-field-initializers -Wno-format-truncation
CXXFLAGS_amd64+=	-DUI_SSE2
LDFLAGS+=	-lX11 -pthread -lfreetype

PLIST_FILES=	bin/gf2

do-build:
	(cd ${WRKSRC} && ${SETENVI} ${CXX} ${PORTNAME}.cpp -o ${PORTNAME} ${CXXFLAGS} ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
