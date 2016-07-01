# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	1.3.40
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	13

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simplified Wrapper and Interface Generator

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf:build
GNU_CONFIGURE=	yes

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

OCTAVE_VER_CMD=	${LOCALBASE}/bin/octave-config -v 2>/dev/null || ${TRUE}

OPTIONS_DEFINE=	LUA DOCS EXAMPLES

LUA_DESC=	Lua support
LUA_USES=	lua:51
LUA_CONFIGURE_ON=	--with-lua=${LUA_BINDIR}/lua \
			--with-luaincl=${LUA_INCDIR} \
			--with-lualib=${LUA_LIBDIR}
LUA_CONFIGURE_OFF=	--without-lua

post-patch:
	@${SETENV} OCTAVE_VER=$$(${OCTAVE_VER_CMD}) \
		${REINPLACE_CMD} -e 's|$$RUBY |${RUBY} |; \
			s|^PHP4CONFIG=.*$$|PHP4CONFIG=php-config|; \
			s|OCTAVEDIR=".*"|OCTAVEDIR="${LOCALBASE}/include/octave-$${OCTAVE_VER}"|; \
			s|MZSCHEME --mute-banner|MZSCHEME|; \
			/^MZDYNOBJ/s|`$$|\| tail -n 1`|; \
			' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/Lib/lua/luarun.swg

post-configure:
	@${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${VER}

post-install-DOCS-on:
	cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${PORTVERSION}

.include <bsd.port.mk>
