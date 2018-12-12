# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scummvm-tools
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	games emulators
MASTER_SITES=	http://www.scummvm.org/frs/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Tools for use with the SCUMMVM game emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS=	lame:audio/lame \
		flac:audio/flac \
		oggenc:audio/vorbis-tools
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpng.so:graphics/png \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libfreetype.so:print/freetype2

USES=		gmake iconv tar:bzip2
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=

STRIP_FILES=	construct_mohawk create_sjisfnt decine decompile degob \
		dekyra deriven descumm desword2 extract_mohawk gob_loadcalc \
		scummvm-tools-cli

DESKTOP_ENTRIES="ScummVM Tools" \
		"" \
		"${DATADIR}/scummvmtools_128.png" \
		"${PORTNAME}" \
		"Games;" \
		false

PORTDOCS=	COPYRIGHT NEWS README TODO

OPTIONS_DEFINE=		WXGTK DOCS
OPTIONS_DEFAULT=	WXGTK

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		2.8
WX_COMP=	wx:lib:build
WX_CONFIG_ARGS=	absolute
GUI_BIN=	tools_gui
PLIST_SUB+=	WX=""
STRIP_FILES+=	scummvm-tools
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
PLIST_SUB+=	WX="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|wxgtk2-2.8-config|${WX_CONFIG:C/.*\///}|' \
		${WRKSRC}/configure

pre-install:
	${STRIP_CMD} ${STRIP_FILES:S|^|${WRKSRC}/|}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
