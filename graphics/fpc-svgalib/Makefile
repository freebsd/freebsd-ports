# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-svgalib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the SVGA graphics library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	SVGA
SVGA_DESC=	Install svgalib low level console graphics library

.include "${MASTERDIR}/Makefile"
