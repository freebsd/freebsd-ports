# Created by: John Merryweather Cooper
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fv

COMMENT=	Free Pascal unit for Delphi support

USES=		fpc
USE_FPC=	rtl-console rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	EXAMPLES

HAVE_EXAMPLES=	yes

.include "${MASTERDIR}/Makefile"
