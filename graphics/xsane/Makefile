# New ports collection makefile for:	xsane
# Date created:			Fri Apr  8 00:18:29 MET DST 1999
# Whom:				Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

PORTNAME=	xsane
PORTVERSION=	0.82
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		sane.1:${PORTSDIR}/graphics/sane-backends

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		xsane.1

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp1
CONFIGURE_ARGS+=	--enable-gimp
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif

pre-everything::
.if !defined(WITH_GIMP)
	@${ECHO_MSG} "*** Note: XSane can be built with a standalone"
	@${ECHO_MSG} "*** X scanner interface as well as a GIMP plug-in."
	@${ECHO_MSG} "*** If you wish to do this, hit Ctrl-C now and use"
	@${ECHO_MSG} "*** \"WITH_GIMP=yes\""
.endif

pre-patch:
	@find ${WRKSRC} -name 'Makefile.in' | xargs ${PERL} -pi -e \
		's|\$$\(sbindir\)||g'

post-install:
	@${SED} 's:/usr/X11R6:${PREFIX}:' ${PKGMESSAGE}

.include <bsd.port.mk>
