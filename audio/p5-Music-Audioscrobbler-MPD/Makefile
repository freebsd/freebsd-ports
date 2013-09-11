# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Music-Audioscrobbler-MPD
PORTVERSION=	0.13
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Module to submit songs to last.fm from MPD

BUILD_DEPENDS=	p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Music-Audioscrobbler-Submit>=0.05:${PORTSDIR}/audio/p5-Music-Audioscrobbler-Submit
RUN_DEPENDS:=	p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Music-Audioscrobbler-Submit>=0.05:${PORTSDIR}/audio/p5-Music-Audioscrobbler-Submit

USES=		perl5
USE_PERL5=	configure

MAN1=	musicmpdscrobble.1
MAN3=	Music::Audioscrobbler::MPD.3

.include <bsd.port.mk>
