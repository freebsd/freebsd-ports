# Ports collection Makefile for:	rebot3
# Date created:				7th May 2011
# Whom:					Chris Rees (utisoft@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	rebot3
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.headmqa.com/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Renames mp3 files using freedb or local CDDB

RUN_DEPENDS=	${SITE_PERL}/CDDB.pm:${PORTSDIR}/audio/p5-CDDB \
		${SITE_PERL}/MP3/ID3v1Tag.pm:${PORTSDIR}/audio/p5-MP3-ID3v1Tag

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
# Yes, we know it's perl, but we don't want to type '.pl' the whole time.
	@${REINPLACE_CMD} -e 's#\(${PORTNAME}\).pl#\1#' \
		-e '1s#/usr/bin/perl#${PERL}#' \
		-e 's#defined (\(@.*\))#\1#' \
		${WRKSRC}/${PORTNAME}.pl ${WRKSRC}/${PORTNAME}.pl.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.pl.1 \
		${MAN1PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.post.mk>
