# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	zmtx-zmrx
PORTVERSION=	1.02
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.netsw.org/net/modem/protocols/zmodem/zmtx-zmrx/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Send and receive files via ZMODEM protocol (unrestrictive)

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USE_CSTD=	gnu89

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/zmrx bin/zmtx man/man1/zmrx.1.gz man/man1/zmtx.1.gz

do-install:
.for f in zmrx zmtx
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
