# New ports collection makefile for:	Xmms
# Date created:			10 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	Xmms
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Xmms
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}

MAINTAINER=	jeremy@external.org
COMMENT=	Interactive remote control shell for xmms

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		${site_perl}/MPEG/MP3Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${site_perl}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${site_perl}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

site_perl=	${SITE_PERL}

PERL_CONFIGURE=	YES

MAN3=		Xmms::Remote.3 \
		Xmms::SongChange.3 \
		Xmms.3 \
		Bundle::Xmms.3

.include <bsd.port.mk>
