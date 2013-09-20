# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	2.0.9
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Generate wrappers for calling C/C++ code from other languages

LICENSE=	GPLv3

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf:env libtool

MAN1=		ccache-swig${VER}.1

VER=		${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

WRKSRC=		${WRKDIR}/${DISTNAME}
CFLAGS+=	-fPIC -DPIC
ALL_TARGET=	swig
PLIST_SUB+=	VER="${VER}"

WANT_LUA=	yes
WANT_LUA_VER=	5.0+

CONFIGURE_ARGS+=--program-suffix=${VER}

NO_STAGE=	yes
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
	${MKDIR} ${EXAMPLESDIR}/${PORTVERSION}
	cd ${WRKSRC}/Examples && ${FIND} . -type d \
		-exec ${INSTALL} -d ${EXAMPLESDIR}/${PORTVERSION}/{} \;
	cd ${WRKSRC}/Examples && ${FIND} . -type f \
		-exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/${PORTVERSION}/{} \;
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/${PORTVERSION}
	cd ${WRKSRC}/Doc && ${FIND} . -type d \
		-exec ${INSTALL} -d ${DOCSDIR}/${PORTVERSION}/{} \;
	cd ${WRKSRC}/Doc && ${FIND} . -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/${PORTVERSION}/{} \;
.endif

.include <bsd.port.post.mk>
