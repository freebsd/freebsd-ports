# New ports collection makefile for:   	bitlbee
# Date created:                        	10 June 2003
# Whom:                                 Peter van Dijk <peter@dataloss.nl>
#
# $FreeBSD$
#

PORTNAME=	bitlbee
PORTVERSION=	0.74a
PORTREVISION=	0
CATEGORIES=	irc
MASTER_SITES=	http://www.lintux.cx/downloads/

MAINTAINER=	peter@dataloss.nl
COMMENT=	An IRC to other chat networks gateway

MAN8=		bitlbee.8

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} --mandir=${PREFIX}/man --config=${PREFIX}/etc/bitlbee
USE_GMAKE=	yes
USE_GNOME=	glib12

pre-install:
	@mkdir -p -m 700 ${PREFIX}/etc/bitlbee

.include <bsd.port.mk>
