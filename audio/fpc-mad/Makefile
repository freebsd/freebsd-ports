PORTREVISION=	4
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-mad

COMMENT=	Free Pascal interface to mad library

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBMAD
LIBMAD_DESC=	Install mad library
OPTIONS_DEFAULT=	LIBMAD

LIBMAD_LIB_DEPENDS=	libmad.so:audio/libmad

.include "${MASTERDIR}/Makefile"
