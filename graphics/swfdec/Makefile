# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.3.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.schleef.org/swfdec/download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		oil-0.3.0:${PORTSDIR}/devel/liboil

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_SDL=	sdl
USE_GNOME=	gnomehack gtk20 libartlgpl2
USE_GSTREAMER=	gconf
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
CFLAGS+=	-I${X11BASE}/include

PLIST_SUB=	VERSION=${PORTVERSION:R}

.if exists(${X11BASE}/bin/gimp-2.2)
WITH_GIMP=yes
.endif

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp-2.0.200:${PORTSDIR}/graphics/gimp
PLIST_SUB+=	GIMP=""
.else
PLIST_SUB+=	GIMP="@comment "
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "Definde WITH_GIMP to build swf gimp plugin"
	@${ECHO} ""

post-patch:
.if !defined(WITH_GIMP)
	@${REINPLACE_CMD} -e 's|gimp-loader||g' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e "s,int16_t,__int16_t," ${WRKSRC}/libswfdec/swfdec_shape.c
	@${REINPLACE_CMD} -e 's|libdir)/gimp/1.3|prefix)/libexec/gimp/2.2|g' ${WRKSRC}/gimp-loader/Makefile.in
	@${REINPLACE_CMD} -e 's|plugin||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
