# ex:ts=8
# Ports collection makefile for:	k3d
# Date created:			Jun 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	k3d
PORTVERSION=	0.6.7.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	dyeske@gmail.com
COMMENT=	3D modeling, animation, and rendering system

BUILD_DEPENDS=	${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	sigc-2:${PORTSDIR}/devel/libsigc++20 \
		freetype.9:${PORTSDIR}/print/freetype2 \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Magick++.10:${PORTSDIR}/graphics/ImageMagick \
		netpbm.1:${PORTSDIR}/graphics/netpbm \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		gts.5:${PORTSDIR}/graphics/gts \
		glibmm-2.4:${PORTSDIR}/devel/glibmm \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		boost_signals.4:${PORTSDIR}/devel/boost \
		execinfo:${PORTSDIR}/devel/libexecinfo

WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_GL=		yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS+=	--without-docbook --without-graphviz \
		--with-truetype=freetype2 --with-imagemagick --with-jpeg \
		--with-python=${PREFIX}  --with-tiff --with-openexr --with-plib \
		--with-png --with-external-boost --with-libxml2
USE_GMAKE=	yes
USE_GNOME+=	gnometarget gtk12 libxslt
USE_LDCONFIG=	yes
MAN1=	k3d.1

OPTIONS=	GNOME "Build for Gnome" off

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
CONFIGURE_ARGS+=	--with-gnome
PLIST_SUB+=	GNOME=""
.else
CONFIGURE_ARGS+=	--without-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

.include <bsd.port.post.mk>
