# New ports collection makefile for:	fpc-gdbm
# Date created: 			2006-06-05
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-gdbm

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the GNU database system

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
