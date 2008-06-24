# New ports collection makefile for:	fpc-gconf
# Date created: 			2006-06-22
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-gconf

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to GConf

USE_FPC=	gtk x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/gnome1/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	GCONF	"Install gconf, a configuration database system"	on

.include "${MASTERDIR}/Makefile"
