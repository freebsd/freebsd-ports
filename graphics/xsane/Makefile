# New ports collection makefile for:	xsane
# Date created:			Fri Apr  8 00:18:29 MET DST 1999
# Whom:				Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

PORTNAME=	xsane
PORTVERSION=	0.96
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/

MAINTAINER=	domi@saargate.de
COMMENT=	Gtk-based X11 frontend for SANE (Scanner Access Now Easy)

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		sane.1:${PORTSDIR}/graphics/sane-backends

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		xsane.1

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp1
CONFIGURE_ARGS+=	--enable-gimp
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
.else
USE_GNOME=	gtk12
CONFIGURE_ARGS+=	--disable-gtk2
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:C/-O[0-9]*//g}"
.endif

pre-everything::
.if !defined(WITH_GIMP)
	@${ECHO_MSG} "*** Note: XSane can be built with a standalone"
	@${ECHO_MSG} "*** X scanner interface as well as a GIMP plug-in."
	@${ECHO_MSG} "*** If you wish to do this, hit Ctrl-C now and use"
	@${ECHO_MSG} "*** \"WITH_GIMP=yes\""
.endif

pre-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} \
		-i "" -e 's|\$$(sbindir)||g'

post-install:
	@${SED} 's:/usr/X11R6:${PREFIX}:' ${PKGMESSAGE}

.include <bsd.port.post.mk>
