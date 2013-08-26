# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inkscape
PORTVERSION=	0.48.4
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME:L}/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Full featured open source SVG editor

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gc:${PORTSDIR}/devel/boehm-gc \
		gsl:${PORTSDIR}/math/gsl \
		gtkspell:${PORTSDIR}/textproc/gtkspell \
		lcms:${PORTSDIR}/graphics/lcms \
		wpg-0.2:${PORTSDIR}/graphics/libwpg \
		png15:${PORTSDIR}/graphics/png \
		Magick++:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	p5-XML-XQL>=0:${PORTSDIR}/textproc/p5-XML-XQL

USE_BZIP2=	yes
USE_GCC=	any
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack desktopfileutils intlhack libxslt
USES=		gettext
GNU_CONFIGURE=	yes
USE_PERL5=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		inkscape.1 inkview.1
NO_MANCOMPRESS=	yes

OPTIONS_DEFINE=	GNOMEVFS POPPLER
OPTIONS_DEFAULT=POPPLER
POPPLER_DESC=	PDF preview rendering
GNOMEVFS_DESC=	Use gnomevfs for loading files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOMEVFS}
USE_GNOME+=		gnomevfs2
CONFIGURE_ARGS+=	--with-gnome-vfs
.else
CONFIGURE_ARGS+=	--without-gnome-vfs
.endif

.if ${PORT_OPTIONS:MPOPPLER}
LIB_DEPENDS+=		poppler-glib:${PORTSDIR}/graphics/poppler-glib
CONFIGURE_ARGS+=	--enable-poppler-cairo
.else
CONFIGURE_ARGS+=	--enable-poppler-cairo=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ieefp.h|ieeefp.h|' \
		${WRKSRC}/src/2geom/bezier-utils.cpp
	@${REINPLACE_CMD} -e 's|libpng >= 1.2|libpng15 >= 1.2|g' \
		-e 's|-ldl||g' \
	    	${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "*.h" -o -name "*.cpp" | ${XARGS} \
		${REINPLACE_CMD} -e 's|glib/gmessages.h|glib/gtestutils.h|g'
.if !defined(WITH_POPPLER)
	@${REINPLACE_CMD} -e 's|poppler|pdisable|g' \
		${WRKSRC}/configure
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
