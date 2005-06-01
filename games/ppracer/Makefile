# New ports collection makefile for:	ppracer
# Date created:				28 May, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppracer
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/ppracer/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	3D Downhill racing game... kindof like TuxRacer Improved

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SDL=	mixer sdl
USE_GL=		yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--with-tcl-inc="${LOCALBASE}/include/tcl8.3" \
		--with-tcl="${LOCALBASE}/lib/tcl8.3" \

.include <bsd.port.mk>
