# New ports collection makefile for:   tuneradio
# Date created:        5 Febuary 2004
# Whom:                pozar
#
# $FreeBSD$
#

PORTNAME=	tuneradio
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.lns.com/papers/tuneradio/ \
				http://cvsup1.theplanet.com/distfiles/

MAINTAINER=	pozar@lns.com
COMMENT=	A command line method of tuning a Brooktree FM tuner card

PLIST_FILES=	bin/tuneradio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tuneradio ${PREFIX}/bin

.include <bsd.port.mk>
