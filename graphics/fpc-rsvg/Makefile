PORTREVISION=	3
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-rsvg

COMMENT=	Free Pascal interface to librsvg2 library

USES=		fpc
USE_FPC=	cairo fcl-base fcl-image fcl-res gtk2 pasjpeg rtl-objpas x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//:S/^/lib/}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBRSVG2
LIBRSVG2_DESC=	Install librsvg2 library
OPTIONS_DEFAULT=	LIBRSVG2

LIBRSVG2_USES=	gnome
LIBRSVG2_USE=	GNOME=librsvg2

.include "${MASTERDIR}/Makefile"
