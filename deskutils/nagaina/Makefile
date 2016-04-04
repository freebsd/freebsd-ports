# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	nagaina
PORTVERSION=	0.1.2
DISTVERSIONSUFFIX=	-sources
PORTREVISION=	10
CATEGORIES=	deskutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Notes-taking application based on Qt 4

LICENSE=	GPLv2

LIB_DEPENDS=	libpthread-stubs.so:devel/libpthread-stubs \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gettext iconv qmake
USE_GNOME=	glib20
USE_QT4=	corelib gui xml moc_build rcc_build uic_build
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender

PORTDOCS=	CHANGELOG TODO
PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES=	"Nagaina" \
			"Notes-taking application" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"${PORTNAME}" \
			"Qt;Office;Utility;" \
			"true"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
