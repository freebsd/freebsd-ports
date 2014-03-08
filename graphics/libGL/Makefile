# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${LIBGLREVISION}
CATEGORIES=	graphics

COMMENT=	OpenGL library that renders using GLX or DRI

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

USES=		pkgconfig
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto:both

SUB_FILES=	pkg-install pkg-deinstall

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
LIBGLREVISION=	0
.else
LIBGLREVISION=	4
.endif

.include "${.CURDIR}/bsd.mesalib.mk"

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

.if !defined(WITH_NEW_XORG)
post-install:
	${RM} ${STAGEDIR}${PREFIX}/include/GL/glu.h
	${RM} ${STAGEDIR}${PREFIX}/include/GL/glu_mangle.h
	${RM} ${STAGEDIR}${PREFIX}/include/GL/internal/dri_interface.h
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/dri.pc
.endif

.include <bsd.port.mk>
