# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-gdbm

COMMENT=	Free Pascal interface to the GNU database system

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	GDBM
GDBM_DESC=	Install the GNU database manager
OPTIONS_DEFAULT=	GDBM

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm

.include "${MASTERDIR}/Makefile"
