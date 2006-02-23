# New ports collection makefile for:    librsvg2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/librsvg2/Makefile,v 1.73 2005/10/11 22:27:04 marcus Exp $
#

PORTNAME=	librsvg2
PORTVERSION=	2.12.7
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.12
DISTNAME=	librsvg-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		popt.0:${PORTSDIR}/devel/popt \
		croco-${CROCO_VERSION}.3:${PORTSDIR}/textproc/libcroco
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/${GTK_VERSION}/engines/libmetal.so:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=  libtool:15
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnomeprefix libartlgpl2 libgsf gtk20 ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-svgz \
		--disable-gtk-doc \
		--without-gimp \
		--with-croco \
		--disable-gnome-vfs

CROCO_VERSION=	0.6
GTK_VERSION=	2.4.0

PLIST_SUB=	GTK_VERSION=${GTK_VERSION}

MAN1=		rsvg.1

OPTIONS=	MOZILLA_PLUGIN "Enable the SVG browser plug-in" no

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 499999
.if defined(WITH_MOZILLA_PLUGIN)
USE_GECKO=	firefox mozilla
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
CONFIGURE_ENV+=	MOZILLA_CONFIG=no
CONFIGURE_ARGS+=--enable-mozilla-plugin=yes

PLIST_SUB+=	PLUGIN=""
.else

CONFIGURE_ARGS+=--enable-mozilla-plugin=no
PLIST_SUB+=	PLUGIN="@comment "
.endif
.else
PLIST_SUB+=	PLUGIN="@comment "
CONFIGURE_ARGS+=--enable-mozilla-plugin=no
.endif

post-patch:
.if defined(WITH_MOZILLA_PLUGIN)
	@${REINPLACE_CMD} -e 's|mozilla-plugin|${GECKO}-plugin|g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
