# New ports collection makefile for:	libgpod
# Date created:				Wed Jan 1 00:48:58 EST 2006
# Whom:					Devon Ryan <dpryan@dpryan.com>
#
# $FreeBSD$
#

PORTNAME=	libgpod
PORTVERSION=	0.8.0
CATEGORIES=	audio
MASTER_SITES=	SF/gtkpod/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	A library for direct access of iPod contents

LICENSE=	LGPL20

LIB_DEPENDS=	plist.1:${PORTSDIR}/devel/libplist \
		tag.1:${PORTSDIR}/audio/taglib \
		sgutils2.2:${PORTSDIR}/sysutils/sg3_utils

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_SQLITE=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-hal --with-html-dir="${PREFIX}/share/doc"

OPTIONS=	PYTHON	"Enable Python bindings"	off \
		MONO	"Enable Mono bindings"		off

PORTDOCS=	ChangeLog NEWS README*

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen \
		swig:${PORTSDIR}/devel/swig13
RUN_DEPENDS:=	${BUILD_DEPENDS}
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_MONO)
USE_GNOME+=	gtksharp20
CONFIGURE_ARGS+=	--with-mono
PLIST_SUB+=	MONO=""
.else
CONFIGURE_ARGS+=	--without-mono
PLIST_SUB+=	MONO="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 800107 && ${OSVERSION} < 900000 || ${OSVERSION} > 900002
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
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, docs,,' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
