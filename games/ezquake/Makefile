PORTNAME=	ezquake
DISTVERSION=	3.2.3
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/ezQuake/ezquake-source/archive/ \
		https://github.com/ezQuake/ezquake-source/releases/download/${PORTVERSION}/
DISTFILES=	${PORTVERSION}.tar.gz \
		${PORTNAME}-ubuntu-${PORTVERSION}-full.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	vvd@unislabs.com
COMMENT=	Modern QuakeWorld client

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjansson.so:devel/jansson \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp

USES=		gl gmake jpeg pkgconfig sdl tcl
USE_GL=		yes
USE_SDL=	sdl2
MAKE_ENV=	TCL_SUFX=${TCL_SHLIB_VER}
.for v in TCL_INCLUDEDIR TCL_LIBDIR DATADIR
MAKE_ENV+=	${v}="${${v}}"
.endfor
WRKSRC=		${WRKDIR}/${PORTNAME}-source-${PORTVERSION}

.include "${.CURDIR}/../quake-data/Makefile.include"

post-patch:
	@${REINPLACE_CMD} -e 's|libtcl\.so|libtcl${TCL_VER:S/.//}|' \
		${WRKSRC}/embed_tcl.h

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "ezquake qw" ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/ezquake-freebsd \
		${STAGEDIR}${PREFIX}/bin/ezquake

.include <bsd.port.mk>
