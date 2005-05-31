# New ports collection makefile for:   mp3butler
# Date created:        30 April 2001
# Whom:                Christopher Preston <rbg@gayteenresource.org>
#
# $FreeBSD$
#

PORTNAME=	mp3butler
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	#

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program for renaming mp3 files

USE_PERL5=	yes

MAN1=		mp3butler.1

do-build:
	(cd ${WRKSRC} && ${SH} ./mkdocs)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3butler.pl ${PREFIX}/bin/mp3butler
	${INSTALL_MAN} ${WRKSRC}/mp3butler.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
.for I in COPYING ChangeLog INSTALL RANT README
	${MKDIR} ${PREFIX}/share/doc/mp3butler
	${INSTALL_DATA} ${WRKSRC}/$I ${PREFIX}/share/doc/mp3butler
.endfor
.endif

.include <bsd.port.mk>
