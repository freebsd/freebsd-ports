PKGNAMESUFFIX=	-mcbopomofo

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
DISTINFO_FILE=	${.CURDIR}/distinfo

COMMENT=	Mcbopomofo support for gcin
LIB_DEPENDS+=	libgcin-im-client.so:chinese/gcin \
		libjson-c.so:devel/json-c \
		libicui18n.so:devel/icu \
		libfmt.so:devel/libfmt
ALL_TARGET=	mcbopomofo-module
BUILD_GCIN_LIST=mcbopomofo
USE_GITHUB=	nodefault
GH_TUPLE=	openvanilla:fcitx5-mcbopomofo:faa4972:mcb/mcbopomofo-src
MCB_SRC=	${WRKSRC}/mcbopomofo-src/data
MCB_DATA=	${STAGEDIR}${PREFIX}/share/gcin/mcbopomofo/data

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gcin ${MCB_DATA} ${STAGEDIR}${PREFIX}/share/icons/gcin
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/modules/mcbopomofo-module.so ${STAGEDIR}${PREFIX}/lib/gcin
.for f in data data-plain-bpmf associated-phrases-v2 bpmfvs-pua bpmfvs-variants
	@${INSTALL_DATA} ${MCB_SRC}/${f}.txt ${MCB_DATA}/mcbopomofo-${f}.txt
.endfor
	@${INSTALL_DATA} ${MCB_SRC}/dictionary_service.json \
		${MCB_DATA}/mcbopomofo-dictionary-service.json
	@${INSTALL_DATA} ${MCB_SRC}/32x32/apps/fcitx_mcbopomofo.png \
		${STAGEDIR}${PREFIX}/share/icons/gcin/mcbopomofo.png

.include "${MASTERDIR}/Makefile"
