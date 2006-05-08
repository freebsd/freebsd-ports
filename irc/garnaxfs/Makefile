# New ports collection makefile for:	garnaxfs
# Date created:			19 Jun 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	garnaxfs
PORTVERSION=	1.1.0
CATEGORIES=	irc
MASTER_SITES=	http://garnax.mircx.com/
DISTNAME=	garnax-f1.1

MAINTAINER=	tlp@liquidx.org
COMMENT=	A file serving bot for IRC

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_FILES=	bin/garnaxfs etc/garnaxfs.sample

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_CFLAGS}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/garnax ${PREFIX}/bin/garnaxfs
	${INSTALL_DATA} ${WRKSRC}/example.conf ${PREFIX}/etc/garnaxfs.sample

.include <bsd.port.mk>
