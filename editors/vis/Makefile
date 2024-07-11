PORTNAME=	vis
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
CATEGORIES=	editors

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Vi-like editor based on Plan 9's structural regular expressions
WWW=		https://github.com/martanne/${PORTNAME}

LICENSE=	CC0-1.0 ISCL MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libtermkey.so:devel/libtermkey
TEST_DEPENDS=	vim>0:editors/vim

USES+=		gmake lua pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	martanne
GH_TAGNAME=	b7074021b7bfb0932b889b9560dd22df31cef818:test

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

INSTALL_TARGET=	install-strip
TEST_TARGET=	test

REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=			LPEG NLS TRE
OPTIONS_DEFAULT=		LPEG TRE
OPTIONS_RADIO=			CLIPBOARD
OPTIONS_RADIO_CLIPBOARD=	WL_COPY XCLIP XSEL
OPTIONS_SUB=			yes

LPEG_DESC=	Syntax highlighting
TRE_DESC=	More memory efficient regex search
WL_COPY_DESC=	Use wl-copy
XCLIP_DESC=	Use xclip
XSEL_DESC=	Use xsel-conrad

LPEG_RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}lpeg>=0.8.1:devel/lua-lpeg@${LUA_FLAVOR}
NLS_USES=		gettext-runtime
TRE_IMPLIES=		NLS
TRE_LIB_DEPENDS=	libtre.so:textproc/libtre
WL_COPY_RUN_DEPENDS=	wl-clipboard>0:x11/wl-clipboard
XCLIP_RUN_DEPENDS=	xclip>0:x11/xclip
XSEL_RUN_DEPENDS=	xsel-conrad>0:x11/xsel-conrad

post-extract:
	${CP} -a ${WRKSRC_test}/test/ ${WRKSRC}/test

post-patch:
	${REINPLACE_CMD} -e 's,%%ETCDIR%%,${ETCDIR},1' \
		-e 's,%%PREFIX%%,${PREFIX},1' \
		${WRKSRC}/man/vis.1 \
		${WRKSRC}/vis-lua.c \
		${WRKSRC}/vis-single.c

post-install:
	@(cd ${STAGEDIR}${PREFIX}/bin; ${MV} vis vise)
	@(cd ${STAGEDIR}${PREFIX}/share/man/man1; ${MV} vis.1 vise.1)

.include <bsd.port.mk>
