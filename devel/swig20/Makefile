# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	2.0.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Generate wrappers for calling C/C++ code from other languages

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake lua:51

VER=		${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION} VER="${VER}"

GNU_CONFIGURE=	yes
ALL_TARGET=	# none

CONFIGURE_ARGS+=--program-suffix=${VER}

CONFIGURE_ARGS+=--with-lua=${LUA_BINDIR}/lua \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}

OCTAVE_VER_CMD=	${LOCALBASE}/bin/octave-config -v 2>/dev/null || ${TRUE}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

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
	cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.mk>
