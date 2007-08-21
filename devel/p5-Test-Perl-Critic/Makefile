# New ports collection makefile for:	p5-Test-Perl-Critic
# Date created:		2007-07-30
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Perl-Critic
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	cherry@trombik.org
COMMENT=	Use Perl::Critic in test programs

RUN_DEPENDS=	p5-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Perl-Critic \
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	yes

MAN3=	Test::Perl::Critic.3

.include <bsd.port.mk>
