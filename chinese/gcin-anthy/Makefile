PKGNAMESUFFIX=	-anthy

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	Anthy support for gcin
BUILD_DEPENDS+=	${LOCALBASE}/include/anthy-unicode-1.0/anthy/anthy.h:japanese/anthy-unicode
LIB_DEPENDS+=	libanthy-unicode.so:japanese/anthy-unicode \
		libgcin-im-client.so:chinese/gcin
MAKE_ENV+=	ANTHY_CFLAGS=-I${LOCALBASE}/include/anthy-unicode-1.0
ALL_TARGET=	anthy-module
BUILD_GCIN_LIST=anthy

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gcin
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/modules/anthy-module.so ${STAGEDIR}${PREFIX}/lib/gcin

.include "${MASTERDIR}/Makefile"
