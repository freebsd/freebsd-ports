# New ports collection makefile for:	tits
# Date created:				9 February 2001
# Whom:					Steve Woodford <scw@netbsd.hut.fi>
#
# $FreeBSD$
#

PORTNAME=       tits
PORTVERSION=	1.0.2
CATEGORIES=	comms
MASTER_SITES=   http://www.mctavish.co.uk/tits/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
MAKE_ENV=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

MAN8=		tits.8
MANCOMPRESSED=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/tits.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/tits.conf ${PREFIX}/etc/tits.conf.default

.include <bsd.port.mk>
