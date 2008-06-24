# New ports collection makefile for:	fpc-gdbm
# Date created: 			2006-06-05
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-gdbm

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the GNU database system

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	GDBM	"Install the GNU database manager"	on

.include "${MASTERDIR}/Makefile"
