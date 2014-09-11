# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	OpenGL library that renders using GLX or DRI

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

USES=		pkgconfig
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto:both

SUB_FILES=	pkg-install pkg-deinstall

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
LIBGLREVISION=	1
LIB_DEPENDS+=	libglapi.so:${PORTSDIR}/graphics/libglapi
.else
LIBGLREVISION=	4
.endif

.include "${.CURDIR}/bsd.mesalib.mk"

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

post-install:
	${RM} -f ${STAGEDIR}${PREFIX}/libdata/pkgconfig/dri.pc
	${RM} -rf ${STAGEDIR}${PREFIX}/include/GL/internal
.if defined(WITH_NEW_XORG)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/.libGL
	@${MV} ${STAGEDIR}${PREFIX}/lib/libGL* \
		${STAGEDIR}${PREFIX}/lib/.libGL/
	${RM} ${STAGEDIR}${PREFIX}/lib/libglapi*
.else
	${RM} ${STAGEDIR}${PREFIX}/include/GL/glu.h
	${RM} ${STAGEDIR}${PREFIX}/include/GL/glu_mangle.h
.endif

.include <bsd.port.mk>
