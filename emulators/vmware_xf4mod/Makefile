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

MAINTAINER=	nsayer@freebsd.org

NO_WRKSUBDIR=	yes

NO_BUILD=	yes

USE_X_PREFIX=	yes

do-extract:
		${MKDIR} ${WRKSRC}
		${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/lib/modules/drivers

.include <bsd.port.mk>
