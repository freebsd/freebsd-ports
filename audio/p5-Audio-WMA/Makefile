# New ports collection makefile for:	p5-Ogg-Vorbis-Header
# Date created:		Sept 11 2004
# Whom:			Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	Audio-WMA
PORTVERSION=	0.7
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Audio
PKGNAMEPREFIX=	p5-

MAINTAINER=	barner@FreeBSD.org
COMMENT=	Fetch info from WMA audio files

PERL_CONFIGURE=	yes

MAN3=		Audio::WMA.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use 5.008/g;' \
		${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
