# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	Gstreamer GL graphics plugin

GST_PLUGIN=	gl
DIST=		bad

PLIST=		${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

pre-build:
	@cd ${WRKSRC}/gst-libs/gst/gl && ${GMAKE}

post-install:
	@cd ${WRKSRC}/gst-libs/gst/gl && ${SETENV} DESTDIR=${STAGEDIR} \
		INSTALL_TARGET=${INSTALL_TARGET} ${GMAKE} install

.include "${MASTERDIR}/Makefile"
