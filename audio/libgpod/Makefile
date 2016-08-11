# Created by: Devon Ryan <dpryan@dpryan.com>
# $FreeBSD$

PORTNAME=	libgpod
PORTVERSION=	0.8.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/gtkpod/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Library for direct access to iPod contents

LICENSE=	LGPL20

LIB_DEPENDS=	libplist.so:devel/libplist \
		libtag.so:audio/taglib \
		libsgutils2.so:sysutils/sg3_utils

USES=		gettext gmake libtool localbase pathfix pkgconfig sqlite:3 tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --disable-udev --without-hal \
		--with-html-dir="${DOCSDIR:H}"
USE_CSTD=	gnu89
USE_GNOME=	gdkpixbuf2 gtk20 intltool
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS IMOBILE PYTHON # MONO
OPTIONS_DEFAULT=IMOBILE
OPTIONS_SUB=	yes

IMOBILE_DESC=	Apple iPhone/iPod Touch support

IMOBILE_LIB_DEPENDS=	libimobiledevice.so:comms/libimobiledevice
IMOBILE_CONFIGURE_ENV=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
IMOBILE_CONFIGURE_WITH=	libimobiledevice

# Mono 4+ doesn't seem to be supported.
MONO_USE=		GNOME=gtksharp20
MONO_CONFIGURE_WITH=	mono
CONFIGURE_ARGS+=	--without-mono
PLIST_SUB+=		MONO="@comment "

PYTHON_BUILD_DEPENDS=	swig2.0:devel/swig20 \
			${PYTHON_SITELIBDIR}/mutagen/__init__.py:audio/py-mutagen
PYTHON_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:audio/py-mutagen
PYTHON_USE=		GNOME=pygobject
PYTHON_USES=		python
PYTHON_CONFIGURE_ENV=	SWIG="${LOCALBASE}/bin/swig2.0"
PYTHON_CONFIGURE_WITH=	python

PORTDOCS=	ChangeLog NEWS README*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMOBILE}
COMMENT:=	${COMMENT:S,iPod,&/iPhone,}
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/ipod-time-sync \
		${STAGEDIR}${PREFIX}/bin

post-install-MONO-off:
	@${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libgpod-sharp.pc

post-install-DOCS-on:
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
