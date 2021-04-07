PORTNAME=	sdump
PORTVERSION=	2015.01.16
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	sue@iwmt.org
COMMENT=	Sixel image dumper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libsixel.so:graphics/libsixel

USE_GITHUB=	yes
GH_ACCOUNT=	uobikiemukot
GH_TAGNAME=	c5fb55b

PLIST_FILES=	bin/sdump libexec/w3m/yaimg-sixel

USES=		jpeg
MAKEFILE=	makefile

#CFLAGS	+=	-I${LOCALBASE}/include -Wall -Wextra -std=c99 -pedantic -O3 -pipe -s
CFLAGS	+=	-I${LOCALBASE}/include -std=c99
LDFLAGS	+=	-L${LOCALBASE}/lib -ljpeg -lpng -lsixel

PORTDOCS=	README.markdown

OPTIONS_DEFINE=	DOCS

post-build:
	@cd ${WRKSRC}/yaimg-sixel && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdump ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/w3m/
	${INSTALL_PROGRAM} ${WRKSRC}/yaimg-sixel/yaimg-sixel ${STAGEDIR}${PREFIX}/libexec/w3m/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
