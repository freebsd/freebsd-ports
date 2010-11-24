# New ports collection makefile for:	p5-Parse-Perl
# Date created:		2010-11-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-Perl
PORTVERSION=	0.005
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Interpret string as Perl source

PERL_CONFIGURE=	yes
USE_PERL5_RUN=	5.8.4+

MAN3=		Parse::Perl.3 \
		Parse::Perl::CopHintsHash.3 \
		Parse::Perl::Environment.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
