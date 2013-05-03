# Created by: Devon Ryan <dpryan@dpryan.com>
# $FreeBSD$

PORTNAME=	libgpod
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/gtkpod/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	A library for direct access of iPod contents

LICENSE=	LGPL20

LIB_DEPENDS=	plist.1:${PORTSDIR}/devel/libplist \
		tag.1:${PORTSDIR}/audio/taglib \
		sgutils2.2:${PORTSDIR}/sysutils/sg3_utils

USE_CSTD=	gnu89
USE_BZIP2=	yes
USES=		gettext
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_SQLITE=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-udev --without-hal \
		--with-html-dir="${PREFIX}/share/doc"
OPTIONS_DEFINE=	IMOBILE PYTHON MONO
OPTIONS_DEFAULT=	IMOBILE
IMOBILE_DESC=	Apple iPhone/iPod Touch support

PORTDOCS=	ChangeLog NEWS README*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
USE_GNOME+=	pygobject
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen \
		swig:${PORTSDIR}/devel/swig13
RUN_DEPENDS:=	${BUILD_DEPENDS}
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MMONO}
USE_GNOME+=	gtksharp20
CONFIGURE_ARGS+=	--with-mono
PLIST_SUB+=	MONO=""
.else
CONFIGURE_ARGS+=	--without-mono
PLIST_SUB+=	MONO="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMOBILE} && (${OSVERSION} > 900002 || \
    ${OSVERSION} < 900000 && ${OSVERSION} > 800107)
COMMENT:=	${COMMENT:S,iPod,&/iPhone,}
LIB_DEPENDS+=	imobiledevice.1:${PORTSDIR}/comms/libimobiledevice
CONFIGURE_ENV+=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
.else
CONFIGURE_ARGS+=	--without-libimobiledevice
.endif

post-patch:
# Adjust pkgconfigdir to the FreeBSD world
	@${REINPLACE_CMD} -e \
		's,libdir)/pkgconfig,prefix)/libdata/pkgconfig,' \
			${WRKSRC}/Makefile.in \
			${WRKSRC}/bindings/mono/libgpod-sharp/Makefile.in
# Allow to build tools without HAL
	@${REINPLACE_CMD} -e \
		'/noinst_PROGRAMS =/s,^,@HAVE_HAL_TRUE@,' \
			${WRKSRC}/tools/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's, docs,,' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
