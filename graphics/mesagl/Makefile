# New ports collection makefile for:    mesagl
# Date created:         Thu 17 Jul 2008
# Whom:                 pfg
#
# $FreeBSD$
#

PORTNAME=	mesagl
PORTVERSION=	5.0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
PKGNAMESUFFIX=	-mangled
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphics library similar to SGI's OpenGL - mangled version

USE_BZIP2=	yes
USE_LDCONFIG=	yes

USE_XORG=	xxf86vm xext xfixes xdamage xt
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
GLINC=		gl.h gl_mangle.h glu.h glu_mangle.h glx.h glx_mangle.h	\
		glext.h glxext.h osmesa.h xmesa.h xmesa_x.h xmesa_xf86.h
GLLIB=		GL GLU GLw OSMesa
GLVER=		14

MAKEFILE=	Makefile.X11
ALL_TARGET=	realclean freebsd

do-install:
	@${MKDIR} ${PREFIX}/include/Mesa/GL
.for i in ${GLINC}
	@${INSTALL_DATA} ${WRKSRC}/include/GL/${i} ${PREFIX}/include/Mesa/GL/
.endfor
	@${MKDIR} ${PREFIX}/lib
.for l in ${GLLIB}
	@${INSTALL_DATA} ${WRKSRC}/lib/libMesa${l}.a ${PREFIX}/lib/
	@${INSTALL_DATA} ${WRKSRC}/lib/libMesa${l}.so.?.? ${PREFIX}/lib/libMesa${l}.so.${GLVER}
	@${LN} -sf ${PREFIX}/lib/libMesa${l}.so.${GLVER} ${PREFIX}/lib/libMesa${l}.so
.endfor

.include <bsd.port.mk>
