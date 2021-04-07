CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-graph

COMMENT=	Free Pascal interface to graphical applications

USES=		fpc
USE_FPC=	sdl x11 ${ARCH:Mi386:S/i386/pthreads/}

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
