CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fppkg

COMMENT=	Free Pascal package manager unit

USES=		fpc
USE_FPC=	dblib fastcgi fcl-async fcl-base fcl-db fcl-fpcunit fcl-json \
		fcl-net fcl-passrc fcl-web fcl-xml httpd22 httpd24 ibase \
		libmicrohttpd mysql odbc openssl oracle postgres pxlib \
		rtl-extra sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
