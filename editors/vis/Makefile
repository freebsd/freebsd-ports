PORTNAME=	vis
DISTVERSION=	0.8
CATEGORIES=	editors
MASTER_SITES=	https://github.com/martanne/${PORTNAME}/releases/download/v${VIS_VER}/:source \
		https://github.com/martanne/${PORTNAME}-test/releases/download/v${VIS_TEST_VER}/:test
DISTFILES=	${PORTNAME}-${VIS_VER}${EXTRACT_SUFX}:source \
		${VIS_TEST_NAME}-${VIS_TEST_VER}${EXTRACT_SUFX}:test

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Vi-like editor based on Plan 9's structural regular expressions
WWW=		https://www.brain-dump.org/projects/vis/

LICENSE=	CC0-1.0 ISCL MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libtermkey.so:devel/libtermkey
TEST_DEPENDS=	vim>0:editors/vim

USES+=		gmake lua pkgconfig

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

INSTALL_TARGET=	install-strip
TEST_TARGET=	test

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

# To be consistent with VIS_TEST_VERSION.
VIS_VER=	${DISTVERSION}
VIS_TEST_VER=	0.5
VIS_TEST_NAME=	${PORTNAME}-test

post-extract:
	${RMDIR} ${WRKSRC}/test
	${MV} ${WRKDIR}/${VIS_TEST_NAME}-${VIS_TEST_VER}/ ${WRKSRC}/test

post-install:
	@(cd ${STAGEDIR}${PREFIX}/bin; ${MV} vis vise)
	@(cd ${STAGEDIR}${PREFIX}/share/man/man1; ${MV} vis.1 vise.1)

.include <bsd.port.mk>
