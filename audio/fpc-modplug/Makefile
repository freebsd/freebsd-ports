# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-modplug

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to modplug library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBMODPLUG
LIBMODPLUG_DESC=	Install modplug library
OPTIONS_DEFAULT=	LIBMODPLUG

LIBMODPLUG_LIB_DEPENDS=	libmodplug.so:${PORTSDIR}/audio/libmodplug

.include "${MASTERDIR}/Makefile"
