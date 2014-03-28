# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scummvm-tools
DISTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	SF/scummvm/${PORTNAME}/${DISTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Tools for use with the SCUMMVM game emulator

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm
BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		oggdec:${PORTSDIR}/audio/vorbis-tools \

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USES=		gmake
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=

OPTIONS_DEFINE=	WXGTK
OPTIONS_DEFAULT=	WXGTK

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		3.0
WX_CONFIG=	${LOCALBASE}/bin/wxgtk2-2.8-config
WX_COMP=	wx:lib:build
WX_UNICODE=	yes
GUI_BIN=	tools_gui
PLIST_SUB=	WX=""
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
PLIST_SUB=	WX="@comment "
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
