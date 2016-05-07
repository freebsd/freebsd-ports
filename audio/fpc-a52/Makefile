# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	audio lang
PKGNAMESUFFIX=	-a52

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to a52 library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBA52
LIBA52_DESC=	Install a52 library
OPTIONS_DEFAULT=	LIBA52

LIBA52_LIB_DEPENDS=	liba52.so:audio/liba52

.include "${MASTERDIR}/Makefile"
