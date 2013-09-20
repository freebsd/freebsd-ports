# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-a52

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to a52 library

USE_FPC=	yes
NO_STAGE=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBA52
LIBA52_DESC= Install a52 library
OPTIONS_DEFAULT=	LIBA52

.include "${MASTERDIR}/Makefile"
