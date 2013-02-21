# Created by: Oscar Bonilla <obonilla@fisicc-ufm.edu>
# $FreeBSD$

PORTNAME=	unix2dos
PORTVERSION=	1.3
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.guug.org/pub/

MAINTAINER=	obonilla@galileo.edu
COMMENT=	Convert ASCII newlines between CR/LF and LF

MAN1=		unix2dos.1 dos2unix.1
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/unix2dos ${PREFIX}/bin/unix2dos
	${LN} -f ${PREFIX}/bin/unix2dos ${PREFIX}/bin/dos2unix
	${INSTALL_MAN} ${WRKDIR}/man1/unix2dos.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man1/dos2unix.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
