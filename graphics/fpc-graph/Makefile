# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-graph

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to graphical applications

USE_FPC=	x11 sdl pthreads

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
