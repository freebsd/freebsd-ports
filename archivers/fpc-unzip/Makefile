# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	archivers lang
PKGNAMESUFFIX=	-unzip

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal routines for unzipping zip files

USE_FPC=	yes

NO_STAGE=	yes
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	UNZIP
UNZIP_DESC=	Install unzip tools
OPTIONS_DEFAULT=	UNZIP

.include "${MASTERDIR}/Makefile"
