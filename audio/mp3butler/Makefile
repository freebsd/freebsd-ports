# New ports collection makefile for:   mp3butler
# Date created:        30 April 2001
# Whom:                Christopher Preston <rbg@gayteenresource.org>
#
# $FreeBSD$
#

PORTNAME=	mp3butler
PORTVERSION=	2.40
CATEGORIES=	audio
MASTER_SITES=	http://iainlea.dyndns.org/software/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program for renaming mp3 files and looking ID3 tags for it

DEPRECATED=	Depends on audio/p5-MusicBrainz-Client which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

RUN_DEPENDS=	${SITE_PERL}/CDDB.pm:${PORTSDIR}/audio/p5-CDDB \
		${SITE_PERL}/MP3/Tag.pm:${PORTSDIR}/audio/p5-MP3-Tag \
	${SITE_PERL}/${PERL_ARCH}/MusicBrainz/Client.pm:${PORTSDIR}/audio/p5-MusicBrainz-Client

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/mp3butler.pl bin/id3butler.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3butler.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/id3butler.pl ${PREFIX}/bin

.include <bsd.port.mk>
