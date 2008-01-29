# New ports collection makefile for:	ezquake
# Date created:				29 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ezquake
PORTVERSION=	1.8.3
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF:ezquake \
		http://www.winimage.com/zLibDll/:minizip
DISTFILES=	${PORTNAME}_source_${PORTVERSION}${EXTRACT_SUFX}:ezquake \
		${PORTNAME}_win32_${PORTVERSION}${EXTRACT_SUFX}:ezquake \
		unzip101e.zip:minizip

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Modern QuakeWorld client

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		pcre.0:${PORTSDIR}/devel/pcre \
		png.5:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_DOS2UNIX=	*.[ch] Makefile*
USE_GMAKE=	yes
USE_TCL=	yes
MAKE_ENV=	TCL_SUFX="${TCL_VER:S/.//}"
.for v in TCL_INCLUDEDIR TCL_LIBDIR
MAKE_ENV+=	${v}="${${v}}"
.endfor
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/.//:S/./-/}_stable

OPTIONS=	GLX "Build GLX client" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		X11 "Build X11 client" on

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GLX) && defined(WITHOUT_X11)
IGNORE=		needs at least one interface (GLX or X11)
.endif

.if !defined(WITHOUT_GLX)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
USE_GL=		yes
ALL_TARGET+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
ALL_TARGET+=	x11
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=YES
.else
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=NO
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libtcl\.so|libtcl${TCL_VER:S/.//}|' \
		${WRKSRC}/embed_tcl.h

do-install:
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${CP} -R ${WRKDIR}/ezquake/* ${WRKDIR}/qw/* ${Q1DIR}/${PORTNAME}
.if !defined(WITHOUT_GLX)
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake-gl.glx \
		${PREFIX}/bin/ezquake-glx
.endif
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake.x11 \
		${PREFIX}/bin/ezquake-x11
.endif

.include <bsd.port.post.mk>
