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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
LIBGLREVISION=	0
.else
LIBGLREVISION=	4
.endif

do-install:
.if ! defined(WITH_NEW_XORG)
	${RM} -f ${WRKSRC}/include/GL/glu*.h
	@${MKDIR} ${PREFIX}/lib/.libGL
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-libgl
.else
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-pkgconfigDATA
	cd ${WRKSRC}/src/glx; ${GMAKE} install
	${MKDIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL && ${COPYTREE_SHARE} \*.h ${PREFIX}/include/GL/
	@${MKDIR} ${PREFIX}/lib/.libGL
	${INSTALL_LIB} ${WRKSRC}/src/glx/.libs/libGL.so ${PREFIX}/lib/.libGL/
	${INSTALL_LIB} ${WRKSRC}/src/glx/.libs/libGL.so.1 ${PREFIX}/lib/.libGL/
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include "${.CURDIR}/bsd.mesalib.mk"

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

.include <bsd.port.mk>
