# New ports collection makefile for:    librsvg2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsvg2
PORTVERSION=	2.2.3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.2
DIST_SUBDIR=	gnome2
DISTNAME=	librsvg-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gdk_pixbuf-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/2.2.0/engines/libmetal.so:${PORTSDIR}/x11-toolkits/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
PLIST_SUB=	GTK_VERSION="2.2.0"

MAN1=		rsvg.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
