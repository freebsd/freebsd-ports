# Ports collection makefile for:  vmware_xf4mod
# Date created:			  7 Mar 2001
# Whom:				  Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vmware_xf4mod
PORTVERSION=	1.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.vmware.com/software/
DISTNAME=	vmware_drv.o
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XFree86 4.x driver module for VMware guests

RUN_DEPENDS=	XFree86:${X_SERVER_PORT}

NO_WRKSUBDIR=	yes

NO_BUILD=	yes

PLIST_FILES=	lib/modules/drivers/vmware_drv.o

USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386

RESTRICTED=	"Not sure if we can redistribute it"
IGNORE=		This module is now part of XFree86 as of 4.1.0
EXPIRATION_DATE=2004-08-20
DEPRECATED=	${IGNORE}

do-extract:
		${MKDIR} ${WRKSRC}
		# Nothing else

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${PREFIX}/lib/modules/drivers

.include <bsd.port.mk>
