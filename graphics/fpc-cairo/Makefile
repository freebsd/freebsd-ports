CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-cairo

COMMENT=	Free Pascal interface to cairo library

USES=		fpc
USE_FPC=	fcl-base fcl-image fcl-res pasjpeg rtl-objpas x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBCAIRO
LIBCAIRO_DESC=	Install cairo vector graphics library
OPTIONS_DEFAULT=	LIBCAIRO

LIBCAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo

.include "${MASTERDIR}/Makefile"
