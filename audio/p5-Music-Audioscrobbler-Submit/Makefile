# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Music-Audioscrobbler-Submit
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Module to submit songs to last.fm from MPD

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Config-Options>=0.8:${PORTSDIR}/devel/p5-Config-Options
RUN_DEPENDS:=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Config-Options>=0.8:${PORTSDIR}/devel/p5-Config-Options

USES=		perl5
USE_PERL5=	configure

MAN3=	Music::Audioscrobbler::Submit.3

.include <bsd.port.mk>
