# ports collection makefile for:	cwdaemon
# Date created:		17 Mar 2005
# Whom:			Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	cwdaemon
PORTVERSION=	0.9.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://pg4i.mattsnetwork.co.uk/download/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio cw (morse code) keyer daemon

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-exec

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc
MAN8=		cwdaemon.8

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${MAKE} install-data
.else
	cd ${WRKSRC}; ${MAKE} install-man
.endif

.include <bsd.port.mk>
