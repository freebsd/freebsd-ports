# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/gnome-speech/Makefile,v 1.21 2006/08/22 00:55:57 ahze Exp $

PORTNAME=	gnome-speech
PORTVERSION=	0.4.25
PORTREVISION=	1
CATEGORIES=	accessibility audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME text-to-speech API

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix libbonobo
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ESPEAK FESTIVAL
ESPEAK_DESC=	Espeak speech synthesizer support
FESTIVAL_DESC=	Festival speech synthesis support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MESPEAK}
LIB_DEPENDS+=	libespeak.so:${PORTSDIR}/audio/espeak
CONFIGURE_ARGS+=--with-espeak-dir=${LOCALBASE}
PLIST_SUB+=	ESPEAK:=""
.else
CONFIGURE_ARGS+=--without-espeak
PLIST_SUB+=	ESPEAK:="@comment "
.endif

.if ${PORT_OPTIONS:MFESTIVAL}
RUN_DEPENDS+=	festival:${PORTSDIR}/audio/festival
PLIST_SUB+=	FESTIVAL=""
.else
CONFIGURE_ARGS+=--without-festival
PLIST_SUB+=	FESTIVAL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/drivers/swift/*.[ch] \
		${WRKSRC}/drivers/dectalk/*.[ch] \
		${WRKSRC}/drivers/theta/*.[ch] \
		${WRKSRC}/drivers/eloquence/*.[ch] \
		${WRKSRC}/drivers/viavoice/*.[ch] \
		${WRKSRC}/drivers/loquendo/*.[ch] \
		${WRKSRC}/drivers/espeak/*.[ch]

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnomespeech.so.7
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/orbit-2.0/GNOME_Speech_module.so

.include <bsd.port.mk>
