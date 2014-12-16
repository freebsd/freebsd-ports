# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	Gstreamer GL graphics plugin

GST_PLUGIN=	gl
DIST=		bad

#USE_CSTD=	gnu89
#USE_CSTD=	c11
#USE_CXXSTD=	c++11
MAKE_ARGS+=	V=1
#USE_GCC=	yes
PLIST=		${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

pre-build:
	@cd ${WRKSRC}/gst-libs/gst/gl && ${GMAKE}

post-install:
	@cd ${WRKSRC}/gst-libs/gst/gl && ${SETENV} DESTDIR=${STAGEDIR} \
		INSTALL_TARGET=${INSTALL_TARGET} ${GMAKE} install

.include "${MASTERDIR}/Makefile"
