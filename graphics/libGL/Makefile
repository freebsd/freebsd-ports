# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${LIBGLREVISION}
CATEGORIES=	graphics

COMMENT=	OpenGL library that renders using GLX or DRI

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libglapi.so:${PORTSDIR}/graphics/libglapi \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto:both \
		presentproto xshmfence

SUB_FILES=	pkg-install pkg-deinstall

.include <bsd.port.options.mk>
.include "${.CURDIR}/bsd.mesalib.mk"

.if defined(WITH_NEW_MESA)
LIBGLREVISION=	3
.else
LIBGLREVISION=	3
.endif

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/.libGL
	@${MV} ${STAGEDIR}${PREFIX}/lib/libGL* \
		${STAGEDIR}${PREFIX}/lib/.libGL/

.include <bsd.port.mk>
