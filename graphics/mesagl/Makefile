# New ports collection makefile for:    Mesa
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $FreeBSD$
#

PORTNAME=	Mesa
PORTVERSION=	3.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
DISTFILES=	MesaLib-${PORTVERSION}${EXTRACT_SUFX} \
		MesaDemos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sobomax@FreeBSD.org

USE_BZIP2=	yes

.if defined(WANT_GGI)
LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--with-ggi=${LOCALBASE}
.endif

GLUTVER=	3
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"
PLIST_SUB=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
SUB_GL=		src
INCLUDE_GL=	include
GLVER=		14
PLIST_SUB+=	XFREE3:=""
.else
SUB_GL=
INCLUDE_GL=
GLVER=		1
PLIST_SUB+=	XFREE3:="@comment "
MAKE_ENV=	INCLUDES="-I${X11BASE}/include -I${WRKSRC}/include -DGLCALLBACKPCAST=\*"
MAKE_ARGS=	-e
.endif

MAKE_ENV+=	SUB_GL=${SUB_GL}		\
		INCLUDE_GL=${INCLUDE_GL}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-configure:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/config.c

post-install:
.for lib in GL GLU
	@${LN} -sf ${PREFIX}/lib/lib${lib}.so ${PREFIX}/lib/libMesa${lib}.so
.endfor
.if ${XFREE86_VERSION} > 3
	@${MKDIR} ${PREFIX}/include/GL
	@cd ${WRKSRC}/include/GL && \
		${INSTALL_DATA} glu.h glut.h ${PREFIX}/include/GL
.endif

.include <bsd.port.post.mk>
