# New ports collection makefile for:	xsane
# Date created:			Fri Apr  8 00:18:29 MET DST 1999
# Whom:				Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

PORTNAME=	xsane
PORTVERSION=	0.61
CATEGORIES=	graphics
MASTER_SITES=	http://www.wolfsburg.de/~rauch/sane/ \
		http://gd.tuwien.ac.at/hci/sane/xsane/ \
		ftp://ftp.mostang.com/pub/sane/xsane/ \

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		sane.1:${PORTSDIR}/graphics/sane \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.4:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--enable-intl-patch
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		xsane.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/aclocal.m4

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
