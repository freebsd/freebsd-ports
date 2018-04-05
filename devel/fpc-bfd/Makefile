# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-bfd

COMMENT=	Free Pascal interface for the GNU Binary Format description

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

RUN_DEPENDS=	${LOCALBASE}/lib/libbfd.a:devel/binutils

.include "${MASTERDIR}/Makefile"
