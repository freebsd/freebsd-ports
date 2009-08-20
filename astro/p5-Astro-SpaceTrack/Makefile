# New ports collection makefile for:	p5-Astro-SpaceTrack
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Astro-SpaceTrack
PORTVERSION=	0.041
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve orbital data from www.space-track.org

RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Params-Util>=0.12:${PORTSDIR}/devel/p5-Params-Util

PERL_CONFIGURE=	yes

MAN3=		Astro::SpaceTrack.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

.include <bsd.port.post.mk>
