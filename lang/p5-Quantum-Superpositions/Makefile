# New ports collection makefile for:	p5-Quantum-Superpositions
# Date created:				01 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Quantum-Superpositions
PORTVERSION=	2.02
CATEGORIES=	lang science perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Quantum
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	QM-like superpositions in Perl

BUILD_DEPENDS=	${SITE_PERL}/Class/Multimethods.pm:${PORTSDIR}/devel/p5-Class-Multimethods
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Quantum::Superpositions.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\$$VERSION)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use warnings/;' \
		${WRKSRC}/lib/Quantum/Superpositions.pm
.endif

.include <bsd.port.post.mk>
