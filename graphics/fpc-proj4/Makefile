# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-proj4

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to proj library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	PROJ
PROJ_DESC=	Install proj library
OPTIONS_DEFAULT=	PROJ

PROJ_LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj

.include "${MASTERDIR}/Makefile"
