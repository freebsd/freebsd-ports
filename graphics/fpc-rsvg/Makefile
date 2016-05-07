# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-rsvg

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to librsvg2 library

USE_FPC=	cairo fcl-base fcl-image fcl-res gtk2 pasjpeg rtl-objpas x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//:S/^/lib/}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBRSVG2
LIBRSVG2_DESC=	Install librsvg2 library
OPTIONS_DEFAULT=	LIBRSVG2

LIBRSVG2_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2

.include "${MASTERDIR}/Makefile"
