# New ports collection makefile for:	xsane
# Version required:		0.45
# Date created:			Fri Apr  8 00:18:29 MET DST 1999
# Whom:				Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

DISTNAME=	xsane-0.45
CATEGORIES=	graphics
MASTER_SITES=	http://www.wolfsburg.de/~rauch/sane/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/ \

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		sane.1:${PORTSDIR}/graphics/sane \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.3:${PORTSDIR}/graphics/png

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		xsane.1

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}"

CONFIGURE_ARGS=	--enable-intl-patch

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
CONFIGURE_ENV+=	LIBS="-Wl,--rpath -Wl,${LOCALBASE}/lib/sane -L${LOCALBASE}/lib"
.else
CONFIGURE_ENV+=	LIBS="-Wl,--rpath -Wl,${LOCALBASE}/lib/sane -L${LOCALBASE}/lib -lcam"
.endif

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
