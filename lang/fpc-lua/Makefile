# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	lang
PKGNAMESUFFIX=	-lua

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to the lua interpreter

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LUA
LUA_DESC=	Install lua library
OPTIONS_DEFAULT=	LUA

LUA_LIB_DEPENDS=	liblua-5.1.so:lang/lua51

.include "${MASTERDIR}/Makefile"
