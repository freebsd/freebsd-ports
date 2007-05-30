# ex:ts=8
# Ports collection makefile for:	v6
# Date created:			Aug 1, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	v6
PORTVERSION=	0.017
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/F/FG/FGLOCK
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An experimental compiler for Perl 6

BUILD_DEPENDS=	p5-Data-Bind>=0.28:${PORTSDIR}/devel/p5-Data-Bind \
		p5-Devel-Caller>=0.10:${PORTSDIR}/devel/p5-Devel-Caller \
		p5-Module-Compile>=0.20:${PORTSDIR}/devel/p5-Module-Compile \
		p5-Moose>=0.10:${PORTSDIR}/devel/p5-Moose \
		p5-Pugs-Compiler-Rule>=0.17:${PORTSDIR}/lang/p5-Pugs-Compiler-Rule \
		p5-Sub-Multi>=0:${PORTSDIR}/devel/p5-Sub-Multi \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	v6.3 \
	Pugs::Compiler::Perl6.3 \
	Pugs::Runtime::Perl6.3

.include <bsd.port.mk>
