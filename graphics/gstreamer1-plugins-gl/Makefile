# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer GL graphics plugin

GST_PLUGIN=	gl
DIST=		bad

PLIST=		${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

pre-build:
	@cd ${WRKSRC}/gst-libs/gst/gl && ${GMAKE}

post-install:
	@cd ${WRKSRC}/gst-libs/gst/gl && ${SETENV} DESTDIR=${STAGEDIR} \
		INSTALL_TARGET=${INSTALL_TARGET} ${GMAKE} install
	${INSTALL_DATA} ${WRKSRC}/pkgconfig/gstreamer-gl.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/gstreamer-gl-1.0.pc

.include "${MASTERDIR}/Makefile"
