# New ports collection makefile for:	ccard
# Date created:				12 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ccard
PORTVERSION=	1.1
CATEGORIES=	finance
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A command line offline credit card validator/analyzer

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/ccard
MAN1=		ccard.1

post-configure:
	${REINPLACE_CMD} -e 's/^CFLAGS/CFLAGS?/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
