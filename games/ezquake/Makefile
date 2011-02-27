# New ports collection makefile for:	ezquake
# Date created:				29 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ezquake
PORTVERSION=	1.9
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/A%29%20Official%20releases/ezQuake%20${PORTVERSION}:ezquake \
		http://www.winimage.com/zLibDll/:minizip

DISTFILES=	${PORTNAME}_source_${PORTVERSION}.7z:ezquake \
		${PORTNAME}_linux-x86_${PORTVERSION}${EXTRACT_SUFX}:ezquake \
		unzip101e.zip:minizip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern QuakeWorld client

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip \
		7z:${PORTSDIR}/archivers/p7zip
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		pcre.0:${PORTSDIR}/devel/pcre \
		png.6:${PORTSDIR}/graphics/png

USE_DOS2UNIX=	*.[ch] Makefile*
USE_GMAKE=	yes
USE_TCL=	yes
MAKE_ENV=	TCL_SUFX="${TCL_VER:S/.//}"
.for v in TCL_INCLUDEDIR TCL_LIBDIR DATADIR
MAKE_ENV+=	${v}="${${v}}"
.endfor
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/.//}_stable_sources

OPTIONS=	GLX "Build GLX client" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		X11 "Build X11 client" on

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GLX) && defined(WITHOUT_X11)
IGNORE=		needs at least one interface (GLX or X11)
.endif

.if !defined(WITHOUT_GLX)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
USE_GL=		yes
ALL_TARGET+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	xxf86dga
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

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		${UNZIP_CMD} -qo ${DISTDIR}/${DISTFILES:C/:.*//:M*.zip} && \
		${TAR} zxf ${DISTDIR}/${DISTFILES:C/:.*//:M*.tar.gz} && \
		7z x ${DISTDIR}/${DISTFILES:C/:.*//:M*.7z} >/dev/null
	@${LN} -s ${WRKSRC}/libs/asmlib.h ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|libtcl\.so|libtcl${TCL_VER:S/.//}|' \
		${WRKSRC}/embed_tcl.h
# Resolve name collision with jpeg-8 and API png
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/image.c

do-install:
.for dir in ezquake qw
	${MKDIR} ${DATADIR}/${dir}
	${CP} -r ${WRKDIR}/${dir}/* ${DATADIR}/${dir}
.endfor
.if !defined(WITHOUT_GLX)
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake-gl.glx \
		${PREFIX}/bin/ezquake-glx
.endif
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake.x11 \
		${PREFIX}/bin/ezquake-x11
.endif

.include <bsd.port.post.mk>
