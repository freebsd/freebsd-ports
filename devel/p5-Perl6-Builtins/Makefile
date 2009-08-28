# New ports collection makefile for:	devel/p5-Perl6-Builtins
# Date created:				2007/07/28
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Perl6-Builtins
PORTVERSION=	0.0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide Perl 5 versions of the new Perl 6 builtins

BUILD_DEPENDS=	p5-Contextual-Return>=0:${PORTSDIR}/devel/p5-Contextual-Return \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Perl6::Builtins.3

.include <bsd.port.mk>
