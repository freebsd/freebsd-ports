CATEGORIES=	devel lang
PKGNAMESUFFIX=	-odata

COMMENT=	Free Pascal interface to odata

USES=		fpc
USE_FPC=	dblib fastcgi fcl-async fcl-base fcl-db fcl-fpcunit fcl-json \
		fcl-net fcl-passrc fcl-res fcl-xml fcl-web httpd22 httpd24 \
		ibase libmicrohttpd mysql odbc openssl oracle postgres pxlib \
		rtl-extra rtl-objpas sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
