PORTNAME=	scummvm-tools
PORTVERSION=	2.9.0
PORTREVISION=	3
CATEGORIES=	games emulators
MASTER_SITES=	https://downloads.scummvm.org/frs/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Tools for use with the SCUMMVM game emulator
WWW=		https://www.scummvm.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lame:audio/lame \
		flac:audio/flac \
		oggenc:audio/vorbis-tools
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libpng.so:graphics/png \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gmake iconv pkgconfig tar:bzip2
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix="${PREFIX}" --enable-verbose-build

DESKTOP_ENTRIES="ScummVM Tools" \
		"" \
		"${DATADIR}/scummvmtools_128.png" \
		"${PORTNAME}" \
		"Utility;Compression;" \
		false

PORTDOCS=	COPYRIGHT NEWS README TODO

OPTIONS_DEFINE=	WXGTK DOCS
OPTIONS_DEFAULT=WXGTK
OPTIONS_SUB=	yes

WXGTK_USE=	WX=3.2
WXGTK_VARS=	WX_COMPS=wx WX_CONFIG_ARGS=absolute
WXGTK_CONFIGURE_ENABLE=	wxwidgets

pre-patch:
	@${REINPLACE_CMD} -e 's|^\(_wxconfig=\).*|\1${WX_CONFIG:C/.*\///}|' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
