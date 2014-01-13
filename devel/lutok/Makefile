# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lutok
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Lightweight C++ API for Lua

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig lua

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
CONFIGURE_ARGS+=	--htmldir=${DOCSDIR}/html
# The distfile contains prebuilt doxygen files.  Specify --without_doxygen so
# we won't rebuild them
CONFIGURE_ARGS+=	--without-doxygen
# TODO: install the tests, once FreeBSD has a system for ports to install tests
CONFIGURE_ARGS+=	--without-atf

# Force the use of the lua version we have chosen via USE_LUA.  If we allow
# lutok's configure script search for one using pkgconfig files, it might pick
# a different version.
CONFIGURE_ARGS+=	LUA_CFLAGS="-I${LUA_INCDIR}"
CONFIGURE_ARGS+=	LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"

MAKE_FLAGS+=	examplesdir=${EXAMPLESDIR}

PORTDOCS=	AUTHORS COPYING NEWS README html
PORTEXAMPLES=	Makefile bindings.cpp hello.cpp interpreter.cpp raii.cpp

PLIST_SUB+=	TESTS="@comment "

post-patch: .SILENT
	@${REINPLACE_CMD} -e 's|@pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
