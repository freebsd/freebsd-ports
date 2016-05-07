# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	audio lang
PKGNAMESUFFIX=	-mad

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to mad library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBMAD
LIBMAD_DESC=	Install mad library
OPTIONS_DEFAULT=	LIBMAD

LIBMAD_LIB_DEPENDS=	libmad.so:audio/libmad

.include "${MASTERDIR}/Makefile"
