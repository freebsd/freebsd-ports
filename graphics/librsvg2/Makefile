# New ports collection makefile for:    librsvg2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsvg2
PORTVERSION=	2.2.5
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.2
DISTNAME=	librsvg-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/2.2.0/engines/libmetal.so:${PORTSDIR}/x11-toolkits/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gtk20 libartlgpl2 libxml2 libgsf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-svgz \
		--disable-gtk-doc
PLIST_SUB=	GTK_VERSION="2.2.0"

MAN1=		rsvg.1

.include <bsd.port.pre.mk>

.if defined(WITH_GIMP) || exists (${X11BASE}/libexec/gimp/1.3/plug-ins/AlienMap)
LIB_DEPENDS+=		gimp-1.3:${PORTSDIR}/graphics/gimp-devel
CONFIGURE_ARGS+=	--with-gimp
PLIST_SUB+=		GIMP:=""
.else
CONFIGURE_ARGS=		--without-gimp
PLIST_SUB+=		GIMP:="@comment "
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Librsvg2 has the following tunable option(s):"
	@${ECHO_MSG} "	WITH_GIMP=yes	Build an svg plugin for gimp-devel (default: auto)"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
