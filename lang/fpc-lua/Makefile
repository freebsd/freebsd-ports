# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-lua

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the lua interpreter

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LUA
LUA_DESC=	Install lua library
OPTIONS_DEFAULT=	LUA

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
