# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-cairo

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to cairo library

USE_FPC=	fcl-async fcl-base fcl-image hash pasjpeg paszlib pthreads \
		x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBCAIRO
LIBCAIRO_DESC=	Install cairo vector graphics library
OPTIONS_DEFAULT=	LIBCAIRO

LIBCAIRO_LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo

.include "${MASTERDIR}/Makefile"
