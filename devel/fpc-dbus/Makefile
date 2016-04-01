# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-dbus

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to dbus library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	DBUS
DBUS_DESC=	Install dbus library
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

.include "${MASTERDIR}/Makefile"
