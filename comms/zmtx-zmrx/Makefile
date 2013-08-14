# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	zmtx-zmrx
PORTVERSION=	1.02
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.netsw.org/net/modem/protocols/zmodem/zmtx-zmrx/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Send and receive files via ZMODEM protocol (unrestrictive)

USE_CSTD=	gnu89

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		zmrx.1 zmtx.1
PLIST_FILES=	bin/zmrx bin/zmtx

do-install:
.for f in zmrx zmtx
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${MANPREFIX}/man/man1
.endfor

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
