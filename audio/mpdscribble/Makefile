# New ports collection makefile for:	mpdscribble
# Date created:		July 13 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mpdscribble
PORTVERSION=	0.2.12
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.frob.nl/projects/scribble/ \
		http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/~tournoij/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/

MAINTAINER=	carpetsmoker@rwxrwxrwx.net
COMMENT=	Musicpd last.fm client

LIB_DEPENDS=	soup:${PORTSDIR}/devel/libsoup22

GNU_CONFIGURE=	yes
MAN1=		mpdscribble.1
PLIST_FILES=	bin/mpdscribble bin/mpdscribble-setup

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${PREFIX}/bin/mpdscribble-setup

.include <bsd.port.mk>
