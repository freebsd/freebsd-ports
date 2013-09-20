# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-newt

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to newt library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	NEWT
NEWT_DESC=	Install newt library
OPTIONS_DEFAULT=	NEWT

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
