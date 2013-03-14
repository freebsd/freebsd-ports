# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-ggi

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libggi

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBGGI
LIBGGI_DESC=	Install ggi library
OPTIONS_DEFAULT=	LIBGGI

.include "${MASTERDIR}/Makefile"
