# New ports collection makefile for:	ccard
# Date created:				12 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ccard
PORTVERSION=	1.1
CATEGORIES=	finance
MASTER_SITES=	http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command line offline credit card validator/analyzer

DEPRECATED=	Project disappeared from the internet
EXPIRATION_DATE=2006-12-03

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ccard
MAN1=		ccard.1

post-configure:
	${REINPLACE_CMD} -e 's/^CFLAGS/CFLAGS?/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
