# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libgd

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libgd for producing graphics files

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBGD
LIBGD_DESC=	Install gd graphic library
OPTIONS_DEFAULT=	LIBGD

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
