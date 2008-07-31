# New ports collection makefile for:	p5-Test-Inline
# Date created:				Mon Sep 12
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Inline
PORTVERSION=	2.208
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Test::Inline - Inlining your tests next to the code being tested

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny \
		${SITE_PERL}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/Class/Autouse.pm:${PORTSDIR}/devel/p5-Class-Autouse \
		${SITE_PERL}/Algorithm/Dependency.pm:${PORTSDIR}/devel/p5-Algorithm-Dependency \
		${SITE_PERL}/File/Flat.pm:${PORTSDIR}/devel/p5-File-Flat \
		${SITE_PERL}/File/chmod.pm:${PORTSDIR}/devel/p5-File-chmod \
		${SITE_PERL}/Test/Script.pm:${PORTSDIR}/devel/p5-Test-Script \
		${SITE_PERL}/Pod/Tests.pm:${PORTSDIR}/devel/p5-Pod-Tests
RUN_DEPENDS=	${BUILD_DEPENDS}

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

.include <bsd.port.mk>
