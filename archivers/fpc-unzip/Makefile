# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	archivers lang
PKGNAMESUFFIX=	-unzip

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal routines for unzipping zip files

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	UNZIP
UNZIP_DESC=	Install unzip tools
OPTIONS_DEFAULT=	UNZIP

UNZIP_RUN_DEPENDS=	unzip:archivers/unzip

.include "${MASTERDIR}/Makefile"
