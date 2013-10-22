# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	1.3.40
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	13

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simplified Wrapper and Interface Generator

USE_AUTOTOOLS=	autoconf:env libtool

VER=		${PORTVERSION:R}

# Supported languages: allegrocl c# clisp chicken guile java lua ocaml Octave
#                      perl php pike python R ruby tcl

WRKSRC=		${WRKDIR}/${DISTNAME}
CFLAGS+=	-fPIC -DPIC
ALL_TARGET=	swig

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}${VER} \
		bin/ccache-${PORTNAME} \
		man/man1/ccache-${PORTNAME}.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*

OPTIONS_DEFINE=	LUA DOCS EXAMPLES
OPTIONS_DEFAULT=DOCS EXAMPLES
LUA_DESC=	Enable Lua support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.0+
LUA_COMPS=	lua:build
CONFIGURE_ARGS+=--with-lua=${LUA_BINDIR}/lua \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}
.else
CONFIGURE_ARGS+=--without-lua
.endif

OCTAVE_VER_CMD=	${LOCALBASE}/bin/octave-config -v 2>/dev/null || ${TRUE}

post-patch:
	${SETENV} OCTAVE_VER=$$(${OCTAVE_VER_CMD}) \
	${REINPLACE_CMD} -e 's|$$RUBY |${RUBY} |; \
		s|^PHP4CONFIG=.*$$|PHP4CONFIG=php-config|; \
		s|OCTAVEDIR=".*"|OCTAVEDIR="${LOCALBASE}/include/octave-$${OCTAVE_VER}"|; \
		s|MZSCHEME --mute-banner|MZSCHEME|; \
		/^MZDYNOBJ/s|`$$|\| tail -n 1`|; \
		' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/Lib/lua/luarun.swg

post-configure:
	${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${VER}
	cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} '*' ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}
	cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DOCSDIR}/${PORTVERSION}

.include <bsd.port.post.mk>
