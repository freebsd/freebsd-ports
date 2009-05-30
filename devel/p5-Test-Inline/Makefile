# New ports collection makefile for:	p5-Test-Inline
# Date created:				Mon Sep 12
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Inline
PORTVERSION=	2.210
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Inline - Inlining your tests next to the code being tested

RUN_DEPENDS=	p5-Algorithm-Dependency>=1.02:${PORTSDIR}/devel/p5-Algorithm-Dependency \
		p5-Class-Autouse>=1.15:${PORTSDIR}/devel/p5-Class-Autouse \
		p5-Config-Tiny>=2.00:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-File-Find-Rule>=0.26:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Flat>=1.00:${PORTSDIR}/devel/p5-File-Flat \
		p5-File-Remove>=0.37:${PORTSDIR}/devel/p5-File-Remove \
		p5-File-Slurp>=9999.04:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-chmod>=0.31:${PORTSDIR}/devel/p5-File-chmod \
		p5-Params-Util>=0.21:${PORTSDIR}/devel/p5-Params-Util \
		p5-Pod-Tests>=0.18:${PORTSDIR}/devel/p5-Pod-Tests
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-ClassAPI>=1.02:${PORTSDIR}/devel/p5-Test-ClassAPI \
		p5-Test-Script>=1.02:${PORTSDIR}/devel/p5-Test-Script

PERL_CONFIGURE=	yes

MAN1=	inline2test.1
MAN3=	Test::Inline.3 \
	Test::Inline::Content.3 \
	Test::Inline::Content::Default.3 \
	Test::Inline::Content::Legacy.3 \
	Test::Inline::Content::Simple.3 \
	Test::Inline::Extract.3 \
	Test::Inline::IO::File.3 \
	Test::Inline::Script.3 \
	Test::Inline::Section.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
RUN_DEPENDS+=	p5-Getopt-Long>=2.34:${PORTSDIR}/devel/p5-Getopt-Long
.endif

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
