# Created by: Anonymous
# $FreeBSD$

PORTNAME=	alien
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	GHC
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lua -> C FFI

LICENSE=	MIT

LIB_DEPENDS=	libffi.so:devel/libffi

USE_GITHUB=	yes
GH_ACCOUNT=	mascarenhas

USES=		libtool lua shebangfix zip
SHEBANG_FILES=	src/constants
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LUA_MODLIBDIR} \
		--datadir=${LUA_MODSHAREDIR} \
		--with-lua-suffix="${LUA_VER_STR}"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LUA_INCDIR} -I${LOCALBASE}/include -DBSD
LDFLAGS+=	-L${LUA_LIBDIR} -L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/lua-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/lua-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-dist_docDATA.*|| ; \
		 /^[[:cntrl:]]/s|install-dist_samplesDATA$$||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/lib|${LOCALBASE}/lib| ; \
		 /luarocks/d' ${WRKSRC}/samples/*.lua

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/alien.* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.lua ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
