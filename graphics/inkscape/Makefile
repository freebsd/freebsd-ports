# New ports collection makefile for:	inkscape
# Date created:		17 Nov 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inkscape
PORTVERSION=	0.48.1
CATEGORIES=	graphics gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME:L}/${PORTNAME:L}/0.48.1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program seeks to become a full featured open source SVG editor

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gc.1:${PORTSDIR}/devel/boehm-gc \
		gsl.15:${PORTSDIR}/math/gsl \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		lcms.1:${PORTSDIR}/graphics/lcms \
		wpg-0.1.1:${PORTSDIR}/graphics/libwpg01 \
		Magick++.4:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	${SITE_PERL}/XML/XQL.pm:${PORTSDIR}/textproc/p5-XML-XQL

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack desktopfileutils intlhack libxslt
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		inkscape.1
MAN1_EN=	inkview.1
MANLANG=	"" fr

OPTIONS=	POPPLER	"Enable libpoppler-cairo for rendering PDF preview" on

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomevfs2} != ""
USE_GNOME+=		gnomevfs2
CONFIGURE_ARGS+=	--with-gnome-vfs
.else
CONFIGURE_ARGS+=	--without-gnome-vfs
.endif

.if defined(WITH_POPPLER)
LIB_DEPENDS+=		poppler-glib.5:${PORTSDIR}/graphics/poppler-gtk
CONFIGURE_ARGS+=	--enable-poppler-cairo
.else
CONFIGURE_ARGS+=	--enable-poppler-cairo=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ieefp.h|ieeefp.h|' \
		${WRKSRC}/src/2geom/bezier-utils.cpp
	@${REINPLACE_CMD} -e 's|libpng >= 1.2|libpng14 >= 1.2|g' \
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

.include <bsd.port.post.mk>
