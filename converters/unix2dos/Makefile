# Created by: Oscar Bonilla <obonilla@fisicc-ufm.edu>
# $FreeBSD$

PORTNAME=	unix2dos
PORTVERSION=	1.3
CATEGORIES=	converters
MASTER_SITES=	CRITICAL

MAINTAINER=	obonilla@galileo.edu
COMMENT=	Convert ASCII newlines between CR/LF and LF

PLIST_FILES=	bin/dos2unix bin/unix2dos \
		man/man1/unix2dos.1.gz man/man1/dos2unix.1.gz
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/unix2dos ${STAGEDIR}${PREFIX}/bin/unix2dos
	${LN} -f ${STAGEDIR}${PREFIX}/bin/unix2dos ${STAGEDIR}${PREFIX}/bin/dos2unix
	${INSTALL_MAN} ${WRKDIR}/man1/unix2dos.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man1/dos2unix.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
