# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lutok
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/lutok/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Lightweight C++ API for Lua

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool lua pkgconfig

OPTIONS_DEFINE=	DOCS EXAMPLES TEST
OPTIONS_DEFAULT=TEST

OPTIONS_SUB=		yes
TEST_CONFIGURE_WITH=	atf
TEST_BUILD_DEPENDS=	atf>=0.21:devel/atf
TEST_RUN_DEPENDS=	atf>=0.21:devel/atf

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
CONFIGURE_ARGS+=	--htmldir=${DOCSDIR}/html
# The distfile contains prebuilt doxygen files.  Specify --without_doxygen so
# we won't rebuild them
CONFIGURE_ARGS+=	--without-doxygen

# Force the use of the lua version we have chosen via USE_LUA.  If we allow
# lutok's configure script search for one using pkgconfig files, it might pick
# a different version.
CONFIGURE_ARGS+=	LUA_CFLAGS="-I${LUA_INCDIR}"
CONFIGURE_ARGS+=	LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"

MAKE_FLAGS+=	examplesdir=${EXAMPLESDIR}
MAKE_FLAGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
MAKE_FLAGS+=	examples_DATA=
.endif

PLIST_SUB+=	TESTS="@comment "

.if ! ${PORT_OPTIONS:MDOCS}
pre-install: .SILENT
	${RM} -rf ${WRKSRC}/api-docs
.endif

.include <bsd.port.mk>
