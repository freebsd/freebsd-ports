# New ports collection makefile for:	p5-MIDI
# Date created:				February 07 2007
# Whom:	      				Alexandr Kovalenko <never@nevermind.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	MIDI
PORTVERSION=	0.82
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	MIDI-Perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for handling MIDI files

PERL_CONFIGURE=	YES

MAN3=		MIDI.3 MIDI::Event.3 MIDI::Filespec.3 MIDI::Opus.3 MIDI::Score.3 \
		MIDI::Simple.3 MIDI::Track.3

.include <bsd.port.pre.mk>

.if defined(WITH_GD)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
