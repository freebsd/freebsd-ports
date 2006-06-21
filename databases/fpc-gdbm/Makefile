# New ports collection makefile for:	fpc-gdbm
# Date created: 			2006-06-05
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-gdbm

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface to the GNU database system

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
