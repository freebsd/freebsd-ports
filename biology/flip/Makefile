# New ports collection makefile for:	flip
# Date created:				26 February 2002
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	flip
PORTVERSION=	2.0.2
CATEGORIES=	biology
MASTER_SITES=	ftp://megasun.bch.umontreal.ca/pub/flip/

MAINTAINER=	tonym@biolateral.com.au
COMMENT=	Flip is  used to find/translate orfs

USE_REINPLACE=	yes

MAN1=		flip.1
PLIST_FILES=	bin/flip

# make it respect CFLAGS

post-configure:
	@${REINPLACE_CMD} -e 's/CFLAGS=//' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flip ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
