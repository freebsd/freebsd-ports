# Ports collection makefile for:		Darkbot
# Date created:		24 February 2003
# Whom:			A. Gabriel <backslash@BSDCode.org>
#
# $FreeBSD$
#

PORTNAME=	darkbot
PORTVERSION=	6f6_r6
CATEGORIES=	irc
MASTER_SITES=	http://darkbot.sourceforge.net/archive/unix/ \
		http://www.BSDCode.org/port/

MAINTAINER=	backslash@BSDCode.org
COMMENT=	IRC talking bot with a very fast algorithm for its database

PLIST=		${WRKDIR}/plist

MAN1=		darkbot.1
MANCOMPRESSED=	yes

GNU_CONFIGURE=	yes
IS_INTERACTIVE=	yes

pre-install:
	${CAT} ${MASTERDIR}/pkg-plist | ${SED} -e "s,/usr/local,${LOCALBASE},g" > ${PLIST}

.include <bsd.port.mk>
