# New ports collection makefile for:	xsane
# Version required:		0.22
# Date created:			Fri Apr  8 00:18:29 MET DST 1999
# Whom:				domi@saargate.de
#
# $Id$
#

DISTNAME=	xsane-0.22
CATEGORIES=	graphics
MASTER_SITES=	http://www.wolfsburg.de/~rauch/sane/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		png.3:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		xsane.1

CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
CONFIGURE_ENV+=	LIBS="-Wl,--rpath -Wl,${LOCALBASE}/lib/sane -L${LOCALBASE}/lib"
.else
CONFIGURE_ENV+=	LIBS="-Wl,--rpath -Wl,${LOCALBASE}/lib/sane -L${LOCALBASE}/lib -lcam"
.endif

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
