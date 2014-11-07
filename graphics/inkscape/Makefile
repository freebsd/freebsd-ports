# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inkscape
PORTVERSION=	0.48.5
CATEGORIES=	graphics gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME:tl}/${PORTNAME:tl}/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Full featured open source SVG editor

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libgc.so:${PORTSDIR}/devel/boehm-gc \
		libgsl.so:${PORTSDIR}/math/gsl \
		libgtkspell.so:${PORTSDIR}/textproc/gtkspell \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libMagick++-6.Q16.so:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	p5-XML-XQL>=0:${PORTSDIR}/textproc/p5-XML-XQL

USE_GNOME=	gtkmm24 intlhack libxslt
USES=		desktop-file-utils gettext gmake libtool pathfix perl5 \
		pkgconfig shebangfix tar:bzip2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-gnome-vfs

python_OLD_CMD?=/usr/bin/env python
python_CMD?=	${LOCALBASE}/bin/python2
SHEBANG_FILES=	cxxtest/cxxtestgen.pl share/extensions/*.p[lm] \
		share/extensions/*.py

OPTIONS_DEFINE=	POPPLER
OPTIONS_DEFAULT=POPPLER
POPPLER_DESC=	PDF preview rendering

.include <bsd.port.options.mk>

_CCVERSION!=	${CC} --version
.if ${_CCVERSION:Mclang}
CPPFLAGS+=	-Wno-mismatched-tags
.endif

.if ${PORT_OPTIONS:MPOPPLER}
LIB_DEPENDS+=		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
CONFIGURE_ARGS+=	--enable-poppler-cairo
.else
CONFIGURE_ARGS+=	--enable-poppler-cairo=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libpng >= 1.2|libpng15 >= 1.2|g' \
		-e 's|-ldl||g' \
	    	${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MPOPPLER}
	@${REINPLACE_CMD} -e 's|poppler|pdisable|g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
