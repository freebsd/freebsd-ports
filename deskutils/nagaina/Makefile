# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	nagaina
PORTVERSION=	0.1.2
DISTVERSIONSUFFIX=	-sources
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Notes-taking application based on Qt 4

LICENSE=	GPLv2

LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

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

.include <bsd.port.options.mk>

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
