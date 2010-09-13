# New ports collection makefile for:	p5-Music-Audioscrobbler-Submit
# Date created:		2008-09-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Music-Audioscrobbler-Submit
PORTVERSION=	0.05
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Module to submit songs to last.fm from MPD

RUN_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		p5-Config-Options>=0.8:${PORTSDIR}/devel/p5-Config-Options

PERL_CONFIGURE=	yes

MAN3=	Music::Audioscrobbler::Submit.3

.include <bsd.port.mk>
