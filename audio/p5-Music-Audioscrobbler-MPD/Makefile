# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Music-Audioscrobbler-MPD
PORTVERSION=	0.13
PORTREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to submit songs to last.fm from MPD

BUILD_DEPENDS=	p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-Music-Audioscrobbler-Submit>=0.05:audio/p5-Music-Audioscrobbler-Submit
RUN_DEPENDS:=	p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-Music-Audioscrobbler-Submit>=0.05:audio/p5-Music-Audioscrobbler-Submit

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
