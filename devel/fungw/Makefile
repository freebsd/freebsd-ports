PORTNAME=	fungw
DISTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.repo.hu/projects/fungw/releases/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	C Function gateway for different programming languages
WWW=		http://www.repo.hu/projects/fungw/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgenht.so:devel/genht

USES=		gmake tar:bz2
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${WITH_DEBUG:D--debug} \
		--CC=${CC} \
		--CFLAGS='${CFLAGS}' \
		--LDFLAGS='${LDFLAGS}'

MAKE_ARGS+=	PREFIX=${PREFIX}
BINARY_ALIAS=	python=${PYTHON_CMD:Ufalse}

# unported extensions: estutter funlisp mawk mruby mujs picol python(2)
OPTIONS_DEFINE=		DOCS DUKTAPE LUA PERL PYTHON3 TCL
OPTIONS_DEFAULT=	DUKTAPE LUA PERL PYTHON3 TCL
OPTIONS_SUB=		DUKTAPE LUA PERL PYTHON3 TCL

DUKTAPE_DESC=	Javascript support through Duktape

DUKTAPE_LIB_DEPENDS=	libduktape.so:lang/duktape-lib
DUKTAPE_CONFIGURE_ON=	--cflags/libs/script/duktape=-I${LOCALBASE}/include \
			--ldflags/libs/script/duktape=-L${LOCALBASE}/lib
LUA_USES=		lua:51
LUA_CONFIGURE_ON=	--cflags/libs/script/lua=-I${LUA_INCDIR} \
			--ldflags/libs/script/lua=!'-L${LUA_LIBDIR} -llua-${LUA_VER}'
PERL_USES=		perl5
PYTHON3_USES=		python
TCL_USES=		tcl

post-install:
	[ '${STRIP}' = -s ] && ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfungw*.so.?

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 504200
BROKEN=	does not compile
.endif

.include <bsd.port.post.mk>
