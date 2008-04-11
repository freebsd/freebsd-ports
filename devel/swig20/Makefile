# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	1.3.35
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Simplified Wrapper and Interface Generator

USE_AUTOTOOLS=	autoconf:261:env libtool:15

VER=		${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# Supported languages: allegrocl c# clisp chicken guile java lua ocaml Octave
#                      perl php pike python R ruby tcl

WRKSRC=		${WRKDIR}/${DISTNAME}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC -DPIC"
ALL_TARGET=	swig
PLIST_SUB+=	VER="${VER}"

WANT_LUA=	yes
WANT_LUA_VER=	5.0+

.include <bsd.port.pre.mk>

.if ${HAVE_LUA:Mlua-5.*} != ""
USE_LUA=	yes
LUA_COMPS=	lua:build
CONFIGURE_ARGS+=--with-lua=${LUA_BINDIR}/lua \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}
.endif

OCTAVE_VER!=	${LOCALBASE}/bin/octave-config -v 2>/dev/null || ${TRUE}

post-patch:
	${REINPLACE_CMD} -e 's|$$RUBY |${RUBY} |; \
		s|^PHP4CONFIG=.*$$|PHP4CONFIG=php-config|; \
		s|OCTAVEDIR=".*"|OCTAVEDIR="${LOCALBASE}/include/octave-${OCTAVE_VER}"|; \
		' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/Lib/lua/luarun.swg

post-configure:
	${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	${LN} -f ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}
	${MKDIR} ${EXAMPLESDIR}/${PORTVERSION}
	cd ${WRKSRC}/Examples && ${FIND} . -type d \
		-exec ${INSTALL} -d ${EXAMPLESDIR}/${PORTVERSION}/{} \;
	cd ${WRKSRC}/Examples && ${FIND} . -type f \
		-exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/${PORTVERSION}/{} \;
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/${PORTVERSION}
	cd ${WRKSRC}/Doc && ${FIND} . -type d \
		-exec ${INSTALL} -d ${DOCSDIR}/${PORTVERSION}/{} \;
	cd ${WRKSRC}/Doc && ${FIND} . -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/${PORTVERSION}/{} \;
.endif

.include <bsd.port.post.mk>
