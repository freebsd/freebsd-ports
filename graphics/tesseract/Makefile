# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tesseract
PORTVERSION=	3.04.01
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Commercial quality open source OCR engine

LICENSE=	APACHE20

LIB_DEPENDS=	liblept.so:graphics/leptonica

USES=		localbase libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-ocr

CONFIGURE_ENV=	LIBLEPT_HEADERSDIR="${LOCALBASE}/include/leptonica"

DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README.md ReleaseNotes
PORTEXAMPLES=	eurotext.tif phototest.tif
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS EXAMPLES TOOLS
OPTIONS_DEFAULT=TOOLS
OPTIONS_SUB=	yes
TOOLS_DESC=	Include training tools
TOOLS_LIB_DEPENDS=libicui18n.so:devel/icu \
		libfontconfig.so:x11-fonts/fontconfig
TOOLS_USES=	compiler:c++11-lib pkgconfig
TOOLS_USE=	GNOME=cairo,glib20,pango

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -DNDEBUG||' ${WRKSRC}/configure

post-build-TOOLS-on:
	@cd ${WRKSRC} && ${MAKE} training

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} testing/eurotext.tif \
		testing/phototest.tif ${STAGEDIR}${EXAMPLESDIR}

post-install-TOOLS-on:
	@cd ${WRKSRC} && ${MAKE} DESTDIR=${STAGEDIR} training-install

.include <bsd.port.mk>
