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

LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	mascarenhas

USES=		libtool lua shebangfix zip
SHEBANG_FILES=	src/constants
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--libdir=${LUA_MODLIBDIR} \
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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} alien.* \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${INSTALL_DATA} *.lua \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
