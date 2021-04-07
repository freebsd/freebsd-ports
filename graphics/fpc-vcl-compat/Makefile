CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-vcl-compat

COMMENT=	Free Pascal interface to VCL components

USES=		fpc
USE_FPC=	dblib fastcgi fcl-async fcl-db fcl-fpcunit fcl-json fcl-net \
		fcl-passrc fcl-xml fcl-web httpd22 httpd24 ibase libmicrohttpd \
		mysql odbc openssl oracle postgres pxlib sqlite rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
