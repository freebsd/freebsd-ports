PKGNAMESUFFIX=	-chewing

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	Chewing support for gcin
LIB_DEPENDS+=	libchewing.so:chinese/libchewing \
		libgcin-im-client.so:chinese/gcin
CMAKE_ARGS+=	-DGCIN_USE_CHEWING:BOOL=ON
ALL_TARGET=	chewing-module
BUILD_GCIN_LIST=chewing

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gcin
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/modules/chewing-module.so ${STAGEDIR}${PREFIX}/lib/gcin

.include "${MASTERDIR}/Makefile"
