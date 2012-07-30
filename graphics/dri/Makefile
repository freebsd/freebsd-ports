# New ports collection makefile for:    dri
# Date created:		8 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm \
		expat.6:${PORTSDIR}/textproc/expat2

USE_PKGCONFIG=	build
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

do-install:
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-dri

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not install on ia64
.endif

.if ${ARCH} != "amd64" || ${ARCH} != "i386"
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER=""
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER=""
PLIST_SUB+=	NOUVEAU_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER=""
PLIST_SUB+=	SIS_DRIVER=""
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER=""
PLIST_SUB+=	UNICHROME_DRIVER=""
.endif

.if ${ARCH} == "arm"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER="@comment "
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER="@comment "
PLIST_SUB+=	TDFX_DRIVER="@comment "
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	I810_DRIVER=""
PLIST_SUB+=	I9X5_DRIVER=""
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER=""
PLIST_SUB+=	NOUVEAU_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER=""
PLIST_SUB+=	SIS_DRIVER=""
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER=""
PLIST_SUB+=	UNICHROME_DRIVER=""
.endif

.if ${ARCH} == "mips"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER="@comment "
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER="@comment "
PLIST_SUB+=	TDFX_DRIVER="@comment "
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

.if ${ARCH} == "powerpc"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER=""
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER="@comment "
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

.include <bsd.port.post.mk>
