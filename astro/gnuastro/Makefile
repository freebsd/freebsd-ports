PORTNAME=	gnuastro
PORTVERSION=	0.23
CATEGORIES=	astro
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU astronomy utilities and library
WWW=		https://www.gnu.org/software/gnuastro/

LICENSE=	GPLv3+

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libwcs.so:astro/wcslib \
		libcurl.so:ftp/curl \
		libgsl.so:math/gsl \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		ghostscript gmake jpeg libtool:build localbase pathfix tar:lz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/tests

INFO=		${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,cflags_add="-O3",:,' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,gcc,$(CC),' \
		${WRKSRC}/bin/buildprog/ui.c
	@${REINPLACE_CMD} -e 's,^make -f,g&,' \
		${WRKSRC}/bin/script/pointing-simulate.sh \
		${WRKSRC}/bin/script/zeropoint.sh

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/etc -name \*.conf \
		-exec ${MV} '{}' '{}.sample' \;

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
