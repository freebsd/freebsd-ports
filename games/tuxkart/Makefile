# New ports collection makefile for:	tuxkart
# Date created:				08 Jun 2001
# Whom:					Alexander Langer <alex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tuxkart
PORTVERSION=		0.0.3
CATEGORIES=		games
MASTER_SITES=		http://tuxkart.sourceforge.net/dist/

MAINTAINER=		ports@FreeBSD.org

BUILD_DEPENDS=		${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include \
				  -I${X11BASE}/include" \
			LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
USE_NEWGCC=		yes
CONFIGURE_ARGS+=	--with-plib=${X11BASE} --bindir=${PREFIX}/bin
USE_X_PREFIX=		yes
USE_MESA=		yes

.include <bsd.port.mk>
