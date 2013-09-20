# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libpng

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libpng, for reading PNG image files

USE_FPC=	zlib

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBPNG
LIBPNG_DESC=	Install png library for manipulating PNG images
OPTIONS_DEFAULT=	LIBPNG

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
