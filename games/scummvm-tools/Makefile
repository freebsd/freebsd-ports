# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scummvm-tools
DISTVERSION=	1.8.0
PORTREVISION= 	1
CATEGORIES=	games emulators
MASTER_SITES=	SF/scummvm/${PORTNAME}/${DISTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Tools for use with the SCUMMVM game emulator

LICENSE=	GPLv2

RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS=	lame:audio/lame \
		flac:audio/flac \
		oggenc:audio/vorbis-tools

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=

STRIP_FILES=	construct_mohawk create_sjisfnt decine decompile degob \
		dekyra deriven descumm desword2 extract_mohawk gob_loadcalc \
		scummvm-tools-cli

OPTIONS_DEFINE=	WXGTK DOCS
OPTIONS_DEFAULT=	WXGTK

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		2.8
WX_COMP=	wx:lib:build
WX_UNICODE=	yes
WX_CONFIG_ARGS=	absolute
GUI_BIN=	tools_gui
PLIST_SUB=	WX=""
STRIP_FILES+=	scummvm-tools
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
PLIST_SUB=	WX="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|wxgtk2-2.8-config|${WX_CONFIG:C/.*\///}|' \
		${WRKSRC}/configure

pre-install:
	${STRIP_CMD} ${STRIP_FILES:S|^|${WRKSRC}/|}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
