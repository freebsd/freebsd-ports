# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vips
PORTVERSION=	7.40.7
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Free image processing system

LICENSE=	LGPL21

LIB_DEPENDS=	libcfitsio.so:${PORTSDIR}/astro/cfitsio \
		liborc-0.4.so:${PORTSDIR}/devel/orc \
		libGraphicsMagick.so:${PORTSDIR}/graphics/GraphicsMagick \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libexif.so:${PORTSDIR}/graphics/libexif	\
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libwebp.so:${PORTSDIR}/graphics/webp \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libmatio.so:${PORTSDIR}/math/matio \
		libgirepository-1.0.so:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		gettext gmake libtool pathfix pkgconfig shebangfix
SHEBANG_FILES=	tools/vips-${PORTVERSION:R} tools/vipsprofile
USE_GNOME=	glib20 libgsf libxml2 pango
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x \
		--without-openslide \
		--with-magickpackage=GraphicsMagick
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=	docs
PYTHON_USES=		python
PYTHON_CONFIGURE_WITH=	python

.include <bsd.port.mk>
