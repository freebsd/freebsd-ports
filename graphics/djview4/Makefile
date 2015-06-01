# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	djview
PORTVERSION=	4.9
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/djvu/DjView/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone Djvu viewer and plugin based on Qt4 toolkit

LICENSE=	GPLv2

LIB_DEPENDS=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre

GNU_CONFIGURE=	yes
USES=		pkgconfig webplugin:native libtool
USE_QT4=	gui network rcc_build uic_build moc_build qmake_build
USE_XORG=	sm ice xt
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--x-includes="${LOCALBASE}/include" \
		--x-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV=	QMAKE="${QMAKE}" \
		QMAKESPEC="${QMAKESPEC}"
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

WRKSRC=		${WRKDIR}/djview4-${PORTVERSION}

WEBPLUGIN_DIR=		${PREFIX}/lib/djview4/plugins
WEBPLUGIN_FILES=	nsdejavu.so

post-patch:
	@${REINPLACE_CMD} -e 's,/netscape/,/djview4/,' \
		${WRKSRC}/nsdejavu/Makefile.in ${WRKSRC}/nsdejavu/nsdejavu.1.in
	@${REINPLACE_CMD} -e 's,@NSDEJAVU_LIBS@,@NSDEJAVU_LIBS@ -lXt -lXext,g' \
		${WRKSRC}/nsdejavu/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/djview4/plugins/nsdejavu.so

.include <bsd.port.mk>
