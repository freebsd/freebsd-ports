# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	2.0.12
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Generate wrappers for calling C/C++ code from other languages

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE-GPL

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake lua:51

VER=		${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION} VER="${VER}"

GNU_CONFIGURE=	yes
ALL_TARGET=	# none
TEST_TARGET=	check

CONFIGURE_ARGS=	--program-suffix=${VER} \
		--with-lua=${LUA_BINDIR}/lua \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}

OCTAVE_VER_CMD=	${LOCALBASE}/bin/octave-config -v 2>/dev/null || ${TRUE}

OPTIONS_DEFINE=	DOCS EXAMPLES

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

post-install-DOCS-on:
	@cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${PORTVERSION}

post-install-EXAMPLES-on:
	@cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}

.include <bsd.port.mk>
