PORTNAME=	fungw
DISTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.repo.hu/projects/fungw/releases/

MAINTAINER=	fuz@fuz.su
COMMENT=	C Function gateway for different programming languages

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bz2
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
BINARY_ALIAS=	python=${PYTHON_CMD:Ufalse}

# unported extensions: estutter funlisp mawk mruby mujs picol python(2)
OPTIONS_DEFINE=	DOCS DUKTAPE LUA PERL PYTHON3 TCL
OPTIONS_DEFAULT=	DUKTAPE LUA PERL PYTHON3 TCL
OPTIONS_SUB=	DUKTAPE LUA PERL PYTHON3 TCL

DUKTAPE_DESC=	Javascript support through Duktape

DUKTAPE_LIB_DEPENDS=	libduktape.so:lang/duktape-lib
LUA_USES=	lua:51
PERL_USES=	perl5
PYTHON3_USES=	python
TCL_USES=	tcl

pre-configure-DUKTAPE-on:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
	    ${WRKSRC}/scconfig/src/scripts/find_duktape.c

pre-configure-LUA-on:
	${REINPLACE_CMD} \
	    -e 's,%%LUA_INCDIR%%,${LUA_INCDIR},' \
	    -e 's,%%LUA_LIBDIR%%,${LUA_LIBDIR},' \
	    -e 's,%%LUA_VER%%,${LUA_VER},' \
	    ${WRKSRC}/scconfig/src/scripts/find_lua.c

# install the genht component
post-install:
	(cd ${WRKSRC}/src_3rd/genht && ${SETENV} ${MAKE_ENV} \
	    ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install)

.include <bsd.port.mk>
