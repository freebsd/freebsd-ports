# New ports collection makefile for:	p5-Music-Audioscrobbler-MPD
# Date created:		2008-09-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Music-Audioscrobbler-MPD
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Module to submit songs to last.fm from MPD

RUN_DEPENDS=	${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Music-Audioscrobbler-Submit>=0.05:${PORTSDIR}/audio/p5-Music-Audioscrobbler-Submit

PERL_CONFIGURE=	yes

MAN1=	musicmpdscrobble.1
MAN3=	Music::Audioscrobbler::MPD.3

.include <bsd.port.mk>
