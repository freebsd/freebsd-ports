# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-dbus

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to dbus library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	DBUS
DBUS_DESC=	Install dbus library
OPTIONS_DEFAULT=	DBUS

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
