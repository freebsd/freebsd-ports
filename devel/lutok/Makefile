# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lutok
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Lightweight C++ API for Lua

LICENSE=	BSD

GNU_CONFIGURE=	yes
USE_LUA=	5.1
USE_LDCONFIG=	yes
USES=		pkgconfig

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

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
CONFIGURE_ARGS+=	LUA_LIBS="-L${LUA_LIBDIR} -llua -lm"

MAKE_FLAGS+=	examplesdir=${EXAMPLESDIR}
.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
MAKE_FLAGS+=	examples_DATA=
.endif

PORTDOCS=	AUTHORS COPYING NEWS README html
PORTEXAMPLES=	Makefile bindings.cpp hello.cpp interpreter.cpp raii.cpp

PLIST_SUB+=	TESTS="@comment "

post-patch: .SILENT
	@${REINPLACE_CMD} -e 's|@pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

# Eliminate empty directories
remove-docsdir: .SILENT
	${RMDIR} ${DOCSDIR}
remove-examplesdir: .SILENT
	${RMDIR} ${EXAMPLESDIR}

.if ! ${PORT_OPTIONS:MDOCS}
pre-install: .SILENT
	${RM} -rf ${WRKSRC}/api-docs
post-install: remove-docsdir
.endif

.if ! ${PORT_OPTIONS:MEXAMPLES}
post-install: remove-examplesdir
.endif

.include <bsd.port.mk>
