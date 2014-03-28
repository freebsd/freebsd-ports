# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-web

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

USE_FPC=	fastcgi fcl-async fcl-base fcl-db fcl-json fcl-net fcl-process \
		fcl-xml hash httpd22 httpd24 ibase mysql odbc oracle paszlib postgres \
		pthreads sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}
OPT=		-Fuunits/${BUILDNAME} -Fu../units/${BUILDNAME} -Fu../* \
		-Fu../../units/${BUILDNAME} -Fu../../../units/${BUILDNAME}

.include "${MASTERDIR}/Makefile"
