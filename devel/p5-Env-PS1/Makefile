# ex:ts=8
# Ports collection makefile for:	Env::PS1
# Date created:			Sep 24, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Env-PS1
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Env
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Prompt string formatter

PERL_MODBUILD=	yes

MAN3=	Env::PS1.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Requiers perl 5.6+, install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
