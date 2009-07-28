# ex:ts=8
# Ports collection makefile for:	k3d
# Date created:			Jun 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	k3d
PORTVERSION=	0.6.7.0
DISTVERSIONSUFFIX=-src
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D modeling, animation, and rendering system

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		gts.5:${PORTSDIR}/graphics/gts \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		boost_signals.4:${PORTSDIR}/devel/boost-libs \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	ppmtompeg:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_GL=		yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-docbook --without-graphviz \
		--with-truetype=freetype2 --with-imagemagick --with-jpeg \
		--with-python=${PYTHONBASE} --with-tiff --with-openexr \
		--with-plib --with-png --with-external-boost --with-libxml2
USE_GMAKE=	yes
USE_GNOME=	gnometarget libxslt
WANT_GNOME=	yes
USE_LDCONFIG=	yes
MAN1=		k3d.1

OPTIONS=	GNOME "Build for Gnome" off

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
USE_GNOME+=	libgnome
CONFIGURE_ARGS+=--with-gnome
PKGNAMESUFFIX=	-gnome
PLIST_SUB+=	GNOME=""
.else
CONFIGURE_ARGS+=--without-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local/include,${LOCALBASE}/include,' \
		-e 's,/usr/local/lib,${LOCALBASE}/lib,' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
