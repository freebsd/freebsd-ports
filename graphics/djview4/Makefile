# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	djview
PORTVERSION=	4.9
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/djvu/DjView/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone Djvu viewer and plugin based on Qt4 toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre \
		libtiff.so:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
USES=		desktop-file-utils libtool pkgconfig webplugin:native
USE_QT4=	gui network linguisttools_build moc_build qmake_build rcc_build \
		uic_build
USE_XORG=	sm ice xt
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--x-includes="${LOCALBASE}/include" \
		--x-libraries="${LOCALBASE}/lib" --disable-desktopfiles
CONFIGURE_ENV=	QMAKE="${QMAKE}" \
		QMAKESPEC="${QMAKESPEC}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

WRKSRC=		${WRKDIR}/djview4-${PORTVERSION}

WEBPLUGIN_DIR=		${PREFIX}/lib/djview4/plugins
WEBPLUGIN_FILES=	nsdejavu.so

post-patch:
	@${REINPLACE_CMD} -e 's,/netscape/,/djview4/,' \
		${WRKSRC}/nsdejavu/Makefile.in ${WRKSRC}/nsdejavu/nsdejavu.1.in
	@${REINPLACE_CMD} -e 's,@NSDEJAVU_LIBS@,& -lXt -lXext,g' \
		${WRKSRC}/nsdejavu/Makefile.in

post-install:
.for f in ${WEBPLUGIN_FILES}
	@${STRIP_CMD} ${STAGEDIR}${WEBPLUGIN_DIR}/${f}
.endfor
.for d in 32 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/apps
	${INSTALL_DATA} ${WRKSRC}/desktopfiles/hi${d}-djview4.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/apps/djvulibre-djview4.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/desktopfiles/djvulibre-djview4.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/djview4/plugins/nsdejavu.so

.include <bsd.port.mk>
