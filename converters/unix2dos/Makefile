# New ports collection makefile for:	unix2dos
# Version required:	1.0
# Date created:		1 February 1999
# Whom:			obonilla@fisicc-ufm.edu
#
# $FreeBSD$
#

DISTNAME=	unix2dos-1.0
CATEGORIES=	converters
MASTER_SITES=	http://www.fisicc-ufm.edu/~obonilla/files/

MAINTAINER=	obonilla@fisicc-ufm.edu

MAN1=		unix2dos.1 dos2unix.1
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/unix2dos ${PREFIX}/bin/unix2dos
	${INSTALL_PROGRAM} ${WRKDIR}/dos2unix ${PREFIX}/bin/dos2unix
	${INSTALL_MAN} ${WRKDIR}/man1/unix2dos.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man1/dos2unix.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
