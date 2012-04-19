# New ports collection makefile for:	fpc-utils
# Date created: 			2006-07-12
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-utils

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Compiler utils

USE_FPC=	chm fcl-base fcl-net fcl-process fcl-res fppkg libcurl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
