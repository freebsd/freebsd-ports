PORTREVISION=	1
CATEGORIES=	lang
PKGNAMESUFFIX=	-utils

COMMENT=	Free Pascal Compiler utilities

USES=		fpc
USE_FPC=	chm dblib fastcgi fcl-async fcl-base fcl-db fcl-fpcunit fcl-js \
		fcl-net fcl-passrc fcl-res fcl-xml fcl-web fcl-json fppkg \
		httpd22 httpd24 ibase libcurl libmicrohttpd mysql odbc openssl \
		oracle pastojs postgres pxlib rtl-extra rtl-generics rtl-objpas \
		sqlite webidl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/utils
EXTRACTUNITDIR=	${WRKUNITDIR} ${FPCSRCDIR}/rtl

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/fpcmake
	${RM} ${STAGEDIR}${PREFIX}/bin/fpcmkcfg

.include "${MASTERDIR}/Makefile"
