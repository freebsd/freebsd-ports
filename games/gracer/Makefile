# New ports collection makefile for:   gracer
# Date created:        Fri Jul 30 20:50:16 MET DST 1999
# Whom:                nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

PORTNAME=	gracer
PORTVERSION=	0.1.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nox@jelal.kn-bremen.de

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tcl82.1:${PORTSDIR}/lang/tcl82

USE_MESA=	YES
USE_AUTOCONF_VER=213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			  -I${LOCALBASE}/include/tcl8.2 \
			  -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
USE_GMAKE=	yes
# for plib (sound):
USE_NEWGCC=	yes
CONFIGURE_ARGS+= --with-plib=${X11BASE}

.include <bsd.port.mk>
