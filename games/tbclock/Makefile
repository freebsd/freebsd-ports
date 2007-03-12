# New ports collection makefile for:	tbclock
# Date created:		9 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tbclock
PORTVERSION=	1.10
CATEGORIES=	games
MASTER_SITES=	http://tamentis.com/projects/tbclock/files/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Binary clock in curses

HAS_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d;/^CFLAGS/d' ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
