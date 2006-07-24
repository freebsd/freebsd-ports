# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-oracle

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to Oracle

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
RUN_DEPENDS=	${ORACLE8_LIB}/env_rdbms.mk:${PORTSDIR}/databases/oracle8-client

ORACLE8_LIB=	${LOCALBASE}/oracle8-client/rdbms/lib
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
