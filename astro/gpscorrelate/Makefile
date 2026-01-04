PORTNAME=	gpscorrelate
PORTVERSION=	2.3
CATEGORIES=	astro geography
MASTER_SITES=	https://github.com/dfandrich/gpscorrelate/releases/download/${PORTVERSION}/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Correlate digital camera photos with GPS data in GPX format
WWW=		https://dfandrich.github.io/gpscorrelate/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libatk-1.0.so:accessibility/at-spi2-core \
		libexiv2.so:graphics/exiv2 \
		libharfbuzz.so:print/harfbuzz

# WARNING: we need desktop-file-utils for the port's Makefile,
# although it does not use MimeTypes, it wants to use the tools
USES=		desktop-file-utils gmake gnome pkgconfig tar:xz

USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libxml2 pango

INSTALL_TARGET=	install-desktop-file
TEST_TARGET=	check

CFLAGS+=	-Wno-deprecated-declarations # GTK3 is noisy during build

PLIST_FILES=	bin/gpscorrelate \
		bin/gpscorrelate-gui \
		share/applications/gpscorrelate.desktop \
		share/icons/hicolor/scalable/apps/gpscorrelate-gui.svg

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_DEFAULT=	DOCS NLS

DOCS_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
DOCS_PLIST_FILES=	share/man/man1/gpscorrelate-gui.1.gz \
			share/man/man1/gpscorrelate.1.gz
DOCS_PORTDOCS=		*

NLS_USES=		gettext
NLS_CFLAGS=		-DENABLE_NLS
NLS_LIBS=		-lintl
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/gpscorrelate.mo \
			share/locale/fr/LC_MESSAGES/gpscorrelate.mo \
			share/locale/ru/LC_MESSAGES/gpscorrelate.mo

post-patch:
	${REINPLACE_CMD} -i.bak -e \
		'/^CFLAGS /d; \
		 /^CC /d; \
		 /^CXX /d; \
		 s|^LIBS *=|LIBS+=|; \
		' \
		${WRKSRC}/Makefile

post-patch-DOCS-off:
	${REINPLACE_CMD} -i.bak -e \
		'/^TARGETS= /s|doc/gpscorrelate.*||; \
		 s|xsltproc|:|; \
		' \
		${WRKSRC}/Makefile

do-install-DOCS-on: do-install-DOCS-off
	${INSTALL_MAN} ${WRKSRC}/doc/gpscorrelate.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${LN} -sf gpscorrelate.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/gpscorrelate-gui.1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASES ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${STAGEDIR}${DOCSDIR}/html

do-install-DOCS-off:
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate-gui ${STAGEDIR}${PREFIX}/bin

post-install-NLS-on:
.for i in de fr ru
	( cd ${WRKSRC} && ${GMAKE} build-po )
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/ \
	&& ${INSTALL_DATA} ${WRKSRC}/po/${i}.gmo ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/gpscorrelate.mo
.endfor

.include <bsd.port.mk>
