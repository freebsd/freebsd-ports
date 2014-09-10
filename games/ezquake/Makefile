# Created by: alepulver
# $FreeBSD$

PORTNAME=	ezquake
PORTVERSION=	1.9
PORTREVISION=	7
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
LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png

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
OPTIONS_SUB=	yes

OPENGL_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
OPENGL_USE=		GL=yes

X11_USE=		XORG=xxf86dga

BROKEN_powerpc=		Does not install on powerpc: signal 2

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENGL}
ALL_TARGET+=	glx
.endif

.if ${PORT_OPTIONS:MX11}
ALL_TARGET+=	x11
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
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "ezquake qw" ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MOPENGL}
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake-gl.glx \
		${STAGEDIR}${PREFIX}/bin/ezquake-glx
.endif
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/release/ezquake.x11 \
		${STAGEDIR}${PREFIX}/bin/ezquake-x11
.endif

.include <bsd.port.post.mk>
