# New ports collection makefile for:	p5-perlbrew
# Date created:		2010-10-20
# Whom:			ports@c0decafe.net <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	perlbrew
PORTVERSION=	0.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-
DISTNAME=	App-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Environment manager

BUILD_DEPENDS=	p5-CPAN-Perl-Releases>=0:${PORTSDIR}/devel/p5-CPAN-Perl-Releases \
		p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Devel-PatchPerl>=0:${PORTSDIR}/devel/p5-Devel-PatchPerl \
		p5-File-Path-Tiny>=0.1:${PORTSDIR}/devel/p5-File-Path-Tiny \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Text-Levenshtein>=0.04:${PORTSDIR}/devel/p5-Text-Levenshtein \
		p5-local-lib>=1:${PORTSDIR}/devel/p5-local-lib
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Spec>=0:${PORTSDIR}/devel/p5-Test-Spec

PERL_CONFIGURE=	yes

MAN1=		perlbrew.1
MAN3=		App::perlbrew.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
