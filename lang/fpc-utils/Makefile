# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	lang
PKGNAMESUFFIX=	-utils

COMMENT=	Free Pascal Compiler utilities

USES=		fpc
USE_FPC=	chm fcl-base fcl-fpcunit fcl-net fcl-passrc fcl-res fcl-xml \
		fppkg libcurl fcl-json rtl-extra rtl-objpas openssl fcl-async \
		fcl-web fcl-db ibase mysql odbc oracle postgres sqlite \
		dblib pxlib fastcgi httpd22 httpd24

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/utils
EXTRACTUNITDIR=	${WRKUNITDIR} ${FPCSRCDIR}/rtl

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/fpcmake
	${RM} ${STAGEDIR}${PREFIX}/bin/fpcmkcfg

.include "${MASTERDIR}/Makefile"
