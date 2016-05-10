# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vips
PORTVERSION=	8.3.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Free image processing system

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		liborc-0.4.so:devel/orc \
		libGraphicsMagick.so:graphics/GraphicsMagick \
		libIlmImf.so:graphics/OpenEXR \
		liblcms2.so:graphics/lcms2 \
		libexif.so:graphics/libexif	\
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libfftw3.so:math/fftw3 \
		libmatio.so:math/matio \
		libgirepository-1.0.so:devel/gobject-introspection
RUN_DEPENDS=	bash:shells/bash

USES=		cpe gettext gmake jpeg libtool pathfix pkgconfig shebangfix
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
PYTHON_CONFIGURE_ENABLE=	pyvips8
PYTHON_USE=			GNOME=pygobject3

.include <bsd.port.mk>
