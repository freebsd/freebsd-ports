# ports collection makefile for:	tlf
# Date created:		10 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	tlf
PORTVERSION=	0.9.19
CATEGORIES=	comms
MASTER_SITES=	http://www.wwns.com/tlf/ \
		http://sharon.esrac.ele.tue.nl/pub/linux/ham/tlf/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio curses based logging program

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

MAN1=		tlf.1

.include <bsd.port.mk>
