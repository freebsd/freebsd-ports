# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	libgphoto2
PORTVERSION=	2.5.23
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/libgphoto/${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Universal digital camera control library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gmake iconv libtool localbase pathfix pkgconfig tar:bzip2
USE_CSTD=	gnu89

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LTDLINCL="-I${LOCALBASE}/include" \
		LIBLTDL="-L${LOCALBASE}/lib -lltdl" \
		PATH="${PATH:C,${HOME}/bin,,}" \
		ac_cv_path_DOT=false \
		ac_cv_path_DOXYGEN=false \
		udevscriptdir=${WRKDIR}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.in \
			configure \
			libgphoto2_port/Makefile.in \
			libgphoto2_port/configure

PLIST_SUB=	VERSION="${PORTVERSION}" VERSION_PORT=0.12.0

OPTIONS_DEFINE=		DOCS GD JPEG LIBEXIF NLS XML
OPTIONS_DEFAULT=	GD JPEG LIBEXIF XML
OPTIONS_SUB=		yes

GD_LIB_DEPENDS=		libgd.so:graphics/gd
GD_CONFIGURE_OFF=	--with-gdlib=no
JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg
LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_CONFIGURE_OFF=	--with-libexif=no
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
XML_USE=		GNOME=libxml2
XML_USES=		gnome
XML_CONFIGURE_OFF=	--with-libxml-2.0=no

post-patch:
.for i in configure libgphoto2_port/configure
	@${REINPLACE_CMD} -e \
		'/FLAGS/s|-g|| ; \
		 /grep -i linux/s|; fi ; then|; else false; fi ; then|' \
		${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		'/^doc_DATA/s|COPYING||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|linux-hotplug||' \
		${WRKSRC}/packaging/Makefile.in

.include <bsd.port.mk>
