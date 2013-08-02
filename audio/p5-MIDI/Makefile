# Created by: Alexandr Kovalenko <never@nevermind.kiev.ua>
# $FreeBSD$

PORTNAME=	MIDI
PORTVERSION=	0.83
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	MIDI-Perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for handling MIDI files

OPTIONS_DEFINE=	GD

USES=		perl5
USE_PERL5=	configure

MAN3=		MIDI.3 MIDI::Event.3 MIDI::Filespec.3 MIDI::Opus.3 MIDI::Score.3 \
		MIDI::Simple.3 MIDI::Track.3

GD_BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
GD_RUN_DEPENDS=		p5-GD>=0:${PORTSDIR}/graphics/p5-GD

.include <bsd.port.mk>
