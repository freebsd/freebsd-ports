# Ports collection makefile for:	ofc
# Date created:				06/21/2006
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	ofc
PORTVERSION=	0.8.1
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	http://ofc.dvoudheusden.net/download/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Objective-C Foundation Classes library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=	sdl
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	GDBM "Add gdbm support" off \
		GMP "Add gmp support" off

.if defined (WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
.endif

.if defined (WITH_GMP)
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4
.endif

.include <bsd.port.mk>
