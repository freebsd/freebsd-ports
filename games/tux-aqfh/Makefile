# New ports collection makefile for:	tux-aqfh
# Date created:				10 Jun 2001
# Whom:					Alexander Langer <alex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tux_aqfh
PORTVERSION=		1.0.10
CATEGORIES=		games
MASTER_SITES=		http://tuxaqfh.sourceforge.net/dist/

MAINTAINER=		ports@FreeBSD.org

BUILD_DEPENDS=		${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include \
				  -I${X11BASE}/include \
				  ${PTHREAD_CFLAGS}" \
			LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib \
			      ${PTHREAD_LIBS}"
USE_NEWGCC=		yes
CONFIGURE_ARGS+=	--with-plib=${X11BASE} --bindir=${PREFIX}/bin
USE_X_PREFIX=		yes
USE_MESA=		yes
MAKE_ENV+=		PTHREAD_LIBS="${PTHREAD_LIBS}" \
			PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

.include <bsd.port.mk>
