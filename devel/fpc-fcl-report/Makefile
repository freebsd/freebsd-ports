CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-report

COMMENT=	Free Pascal report (FCL)

USES=		fpc
USE_FPC=	dblib fastcgi fcl-async fcl-base fcl-db fcl-fpcunit fcl-image \
		fcl-json fcl-net fcl-passrc fcl-pdf fcl-xml fcl-web httpd22 \
		httpd24 ibase libmicrohttpd mysql odbc openssl oracle pasjpeg \
		postgres pxlib rtl-extra sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
