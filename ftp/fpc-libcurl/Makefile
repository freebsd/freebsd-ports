# New ports collection makefile for:	fpc-libcurl
# Date created:		2007-09-11
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	ftp lang
PKGNAMESUFFIX=	-libcurl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libcurl

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBCURL	"Install curl tools and library "	on

.include "${MASTERDIR}/Makefile"
