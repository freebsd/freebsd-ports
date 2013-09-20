# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-mad

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to mad library

USE_FPC=	yes
NO_STAGE=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBMAD
LIBMAD_DESC=	Install mad library
OPTIONS_DEFAULT=	LIBMAD

.include "${MASTERDIR}/Makefile"
