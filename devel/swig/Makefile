# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	4.0.2
CATEGORIES=	devel
MASTER_SITES=	SF/swig/swig/swig-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate wrappers for calling C/C++ code from other languages

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE-GPL

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		lua:build

ALL_TARGET=	# empty
CFLAGS+=	-fPIC -DPIC
CONFIGURE_ARGS=	--with-lua=${LOCALBASE}/bin/${LUA_CMD} \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-configure:
	@${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ccache-swig ${STAGEDIR}${PREFIX}/bin/swig

post-install-DOCS-on:
	cd ${WRKSRC}/Doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${PORTVERSION}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/Examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}

.include <bsd.port.mk>
