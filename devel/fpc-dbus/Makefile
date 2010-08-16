# New ports collection makefile for:	fpc-dbus
# Date created:		2010-04-22
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-dbus

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to dbus library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	DBUS	"Install dbus library"	on

.include "${MASTERDIR}/Makefile"
