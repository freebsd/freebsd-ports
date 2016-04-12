# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/gnome-speech/Makefile,v 1.21 2006/08/22 00:55:57 ahze Exp $

PORTNAME=	gnome-speech
PORTVERSION=	0.4.25
PORTREVISION=	2
CATEGORIES=	accessibility audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME text-to-speech API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gnomeprefix libbonobo
USES=		gmake libtool:keepla pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ESPEAK FESTIVAL
ESPEAK_DESC=	Espeak speech synthesizer support
FESTIVAL_DESC=	Festival speech synthesis support

OPTIONS_SUB=	yes

ESPEAK_LIB_DEPENDS=	libespeak.so:audio/espeak
ESPEAK_CONFIGURE_ON=--with-espeak-dir=${LOCALBASE}
ESPEAK_CONFIGURE_OFF=--without-espeak

FESTIVAL_RUN_DEPENDS=	festival:audio/festival
FESTIVAL_CONFIGURE_OFF=--without-festival

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
