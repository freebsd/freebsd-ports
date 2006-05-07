# New ports collection makefile for:    Mesa
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $FreeBSD$
#

PORTNAME=	Mesa
PORTVERSION=	5.0.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
DISTFILES=	MesaLib-${PORTVERSION}${EXTRACT_SUFX} \
		MesaDemos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphics library similar to SGI's OpenGL

CONFLICTS=	XFree86-libraries-[0-9]* xorg-libraries-[0-9]*

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes

.if defined(WANT_GGI)
LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--with-ggi=${LOCALBASE}
.endif

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	GLVER="${GLVER}" LIBS="-lm"
SUB_GL=		src si-glu src-glu
INCLUDE_GL=	include
GLVER=		14
MAKE_ENV+=	SUB_GL="${SUB_GL}"		\
		INCLUDE_GL=${INCLUDE_GL}

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
IGNORE=		is unnecessary because libGL and libGLU come with XFree86 4.0 and higher
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.for lib in GL GLU
	@${LN} -sf ${PREFIX}/lib/lib${lib}.so ${PREFIX}/lib/libMesa${lib}.so
.endfor

.include <bsd.port.post.mk>
