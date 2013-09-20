# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-rsvg

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to librsvg2 library

USE_FPC=	gtk2

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//:S/^/lib/}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBRSVG2
LIBRSVG2_DESC=	Install librsvg2 library
OPTIONS_DEFAULT=	LIBRSVG2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
