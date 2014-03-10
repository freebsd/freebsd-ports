# Created by: vanilla
# $FreeBSD$

PORTNAME=	ofc
PORTVERSION=	0.8.1
PORTREVISION=	9
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Objective-C Foundation Classes library

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2

PROJECTHOST=	${PORTNAME}
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool
USES=		pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15 ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	GDBM GMP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=	libgdbm.so:${PORTSDIR}/databases/gdbm
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp
.endif

.if ${OSVERSION} >= 900000
# 'obj/obj-api.h' deprecated on gcc4.7, so ofc require gcc4.6 or early version.
USE_GCC=	4.6
.endif

.include <bsd.port.mk>
