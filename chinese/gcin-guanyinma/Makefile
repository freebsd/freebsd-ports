PKGNAMESUFFIX=	-guanyinma

MASTERDIR=	${.CURDIR}/../../chinese/gcin
FILESDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
DISTINFO_FILE=	${.CURDIR}/distinfo

COMMENT=	Guanyinma support for gcin
LIB_DEPENDS+=	libgcin-im-client.so:chinese/gcin \
		libjson-c.so:devel/json-c
ALL_TARGET=	guanyinma-module
BUILD_GCIN_LIST=guanyinma
USE_GITHUB=	nodefault
GH_TUPLE=	polobread:KeyKey:v1.5.0:keykey/keykey
GYM_SRC=	${WRKSRC}/keykey
GYM_DATA=	${STAGEDIR}${PREFIX}/share/gcin/guanyinma/data
CARGO_CARGOLOCK=	${WRKSRC}/keykey/Source/Guanyinma/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/keykey/Source/Guanyinma/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
MAKE_ENV+=	${CARGO_ENV}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gcin ${STAGEDIR}${PREFIX}/share/gcin/guanyinma \
		${STAGEDIR}${PREFIX}/share/icons/gcin
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/modules/guanyinma-module.so ${STAGEDIR}${PREFIX}/lib/gcin
	@${INSTALL_DATA} ${GYM_SRC}/Source/Distributions/Takao/CookedDatabase/KeyKey.db \
		${STAGEDIR}${PREFIX}/share/gcin/guanyinma
	@${INSTALL_DATA} ${FILESDIR}/guanyinma.png \
		${STAGEDIR}${PREFIX}/share/icons/gcin/guanyinma.png

.include "${.CURDIR}/Makefile.crates"
.include "${MASTERDIR}/Makefile"
