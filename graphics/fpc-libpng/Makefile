# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libpng

COMMENT=	Free Pascal interface to libpng, for reading PNG image files

USES=		fpc:run
USE_FPC=	zlib

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBPNG
LIBPNG_DESC=	Install png library for manipulating PNG images
OPTIONS_DEFAULT=	LIBPNG

LIBPNG_LIB_DEPENDS=	libpng.so:graphics/png

.include "${MASTERDIR}/Makefile"
