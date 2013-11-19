# Created by: alepulver
# $FreeBSD$

PORTNAME=	ezquake
PORTVERSION=	1.9
PORTREVISION=	6
PORTEPOCH=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTVERSION}:ezquake \
		http://www.winimage.com/zLibDll/:minizip

DISTFILES=	${PORTNAME}_source_${PORTVERSION}.7z:ezquake \
		${PORTNAME}_linux-x86_${PORTVERSION}${EXTRACT_SUFX}:ezquake \
		unzip101e.zip:minizip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern QuakeWorld client

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		7z:${PORTSDIR}/archivers/p7zip
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		pcre.3:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png

USES=		gmake tcl dos2unix
DOS2UNIX_GLOB=	*.[ch] Makefile*
USE_CSTD=	gnu89
MAKE_ENV=	TCL_SUFX=${TCL_SHLIB_VER}
.for v in TCL_INCLUDEDIR TCL_LIBDIR DATADIR
MAKE_ENV+=	${v}="${${v}}"
.endfor
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/.//}_stable_sources

OPTIONS_MULTI=	OUTPUT
OPTIONS_MULTI_OUTPUT=	X11 OPENGL
OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPENGL X11 OPTIMIZED_CFLAGS

NO_STAGE=	yes
.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc: signal 2
.endif

.if ${PORT_OPTIONS:MOPENGL}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
USE_GL=		yes
ALL_TARGET+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xxf86dga
ALL_TARGET+=	x11
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
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

do-install:
.for dir in ezquake qw
	${MKDIR} ${DATADIR}/${dir}
	${CP} -r ${WRKDIR}/${dir}/* ${DATADIR}/${dir}
.endfor
.if ${PORT_OPTIONS:MOPENGL}
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake-gl.glx \
		${PREFIX}/bin/ezquake-glx
.endif
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake.x11 \
		${PREFIX}/bin/ezquake-x11
.endif

.include <bsd.port.post.mk>
