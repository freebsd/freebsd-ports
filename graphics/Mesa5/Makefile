# New ports collection makefile for:    Mesa5
# Date created:         Sun Mar 9 12:02:49  2003
# Whom:                 bobby
#
# $FreeBSD$
#

PORTNAME=	Mesa
PORTVERSION=	5.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
DISTFILES=	MesaLib-${PORTVERSION}${EXTRACT_SUFX} \
		MesaDemos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bobby3999@yahoo.com
COMMENT=	A graphics library similar to SGI's OpenGL

USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS+=--without-glut --prefix=${PREFIX}

.if defined(WANT_GGI)
LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--with-ggi=${LOCALBASE}
.endif

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.ifdef USE_MESA
.error You have `USE_MESA' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

post-install:
.for lib in GL GLU
	@${LN} -sf ${PREFIX}/lib/lib${lib}.so ${PREFIX}/lib/libMesa${lib}.so
.endfor

.include <bsd.port.post.mk>
