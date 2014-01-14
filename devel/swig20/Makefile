# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	2.0.11
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Generate wrappers for calling C/C++ code from other languages

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake
USE_AUTOTOOLS=	autoconf:env libtool

VER=		${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION} VER="${VER}"

CFLAGS+=	-fPIC -DPIC
ALL_TARGET=	# none

WANT_LUA=	yes
WANT_LUA_VER=	5.0+

CONFIGURE_ARGS+=--program-suffix=${VER}

.include <bsd.port.pre.mk>

.if ${HAVE_LUA:Mlua-5.*} != ""
USE_LUA=	yes
LUA_COMPS=	lua:build
CONFIGURE_ARGS+=--with-lua=${LUA_BINDIR}/lua \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}
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
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}
	cd ${WRKSRC}/Examples && ${FIND} . -type d \
		-exec ${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}/{} \;
	cd ${WRKSRC}/Examples && ${FIND} . -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}/{} \;
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${PORTVERSION}
	cd ${WRKSRC}/Doc && ${FIND} . -type d \
		-exec ${INSTALL} -d ${STAGEDIR}${DOCSDIR}/${PORTVERSION}/{} \;
	cd ${WRKSRC}/Doc && ${FIND} . -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/${PORTVERSION}/{} \;
.endif

regression-test: build
	cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.post.mk>
