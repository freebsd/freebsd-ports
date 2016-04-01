# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	3.0.8
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	30

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate wrappers for calling C/C++ code from other languages

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

OPTIONS_DEFINE=	DOCS EXAMPLES

ALL_TARGET=	# empty
CFLAGS+=	-fPIC -DPIC
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:R} \
		--with-lua=${LOCALBASE}/bin/${LUA_CMD} \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}
GNU_CONFIGURE=	yes
TEST_TARGET=	check
USES=		gmake lua

PLIST_FILES=	bin/ccache-swig${PORTVERSION:R} \
		bin/swig${PORTVERSION:R}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OCTAVE_VER_CMD=	${LOCALBASE}/bin/octave-config -v 2>/dev/null || ${TRUE}

post-patch:
	@${SETENV} OCTAVE_VER=$$(${OCTAVE_VER_CMD}) ${REINPLACE_CMD} \
		-e 's|$$RUBY |${RUBY} |' \
		-e 's|^PHP4CONFIG=.*$$|PHP4CONFIG=php-config|' \
		-e 's|OCTAVEDIR=".*"|OCTAVEDIR="${LOCALBASE}/include/octave-$${OCTAVE_VER}"|' \
		-e 's|MZSCHEME --mute-banner|MZSCHEME|' \
		-e '/^MZDYNOBJ/s|`$$|\| tail -n 1`|' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/Lib/lua/luarun.swg

post-configure:
	${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ccache-swig${PORTVERSION:R} ${STAGEDIR}${PREFIX}/bin/swig${PORTVERSION:R}

post-install-DOCS-on:
	cd ${WRKSRC}/Doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${PORTVERSION}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/Examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}

.include <bsd.port.mk>
