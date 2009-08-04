# New ports collection makefile for:	lang/p5-signatures
# Date created:				04 August 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	signatures
PORTVERSION=	0.06
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/F/FL/FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Subroutine signatures for Perl with no source filter

BUILD_DEPENDS=	p5-B-Hooks-OP-Check>=0.18:${PORTSDIR}/devel/p5-B-Hooks-OP-Check \
		p5-B-Hooks-Parser>=0.07:${PORTSDIR}/devel/p5-B-Hooks-Parser \
		p5-B-Hooks-OP-PPAddr>0:${PORTSDIR}/devel/p5-B-Hooks-OP-PPAddr \
		p5-ExtUtils-Depends>=0.302:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-B-Hooks-EndOfScope>=0.08:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	signatures.3

.include <bsd.port.mk>
