# Created by: Devon Ryan <dpryan@dpryan.com>
# $FreeBSD$

PORTNAME=	libgpod
PORTVERSION=	0.8.3
CATEGORIES=	audio
MASTER_SITES=	SF/gtkpod/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Library for direct access to iPod contents

LICENSE=	LGPL20

LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist \
		libtag.so:${PORTSDIR}/audio/taglib \
		libsgutils2.so:${PORTSDIR}/sysutils/sg3_utils

USE_GNOME=	gdkpixbuf2 gtk20
USE_SQLITE=	3
USES=		gettext gmake pathfix pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-udev --without-hal \
		--with-html-dir="${DOCSDIR:H}"
USE_CSTD=	gnu89
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS IMOBILE MONO PYTHON
OPTIONS_DEFAULT=IMOBILE
OPTIONS_SUB=	yes

IMOBILE_DESC=	Apple iPhone/iPod Touch support

MONO_USE=		GNOME=gtksharp20
MONO_CONFIGURE_WITH=	mono

PYTHON_BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20 \
			${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen
PYTHON_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen
PYTHON_USE=		GNOME=pygobject PYTHON=yes
PYTHON_CONFIGURE_ENV=	SWIG="${LOCALBASE}/bin/swig2.0"
PYTHON_CONFIGURE_WITH=	python

PORTDOCS=	ChangeLog NEWS README*

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMOBILE} && (${OSVERSION} > 900002 || \
	${OSVERSION} < 900000 && ${OSVERSION} > 800107)
COMMENT:=	${COMMENT:S,iPod,&/iPhone,}
LIB_DEPENDS+=	libimobiledevice.so:${PORTSDIR}/comms/libimobiledevice
CONFIGURE_ENV+=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
.else
CONFIGURE_ARGS+=--without-libimobiledevice
.endif

post-patch:
# Allow to build tools without HAL
	@${REINPLACE_CMD} -e '/noinst_PROGRAMS =/ s,^,@HAVE_HAL_TRUE@,' \
		${WRKSRC}/tools/Makefile.in

post-install:
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
