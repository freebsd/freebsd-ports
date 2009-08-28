# New ports collection makefile for:	devel/p5-Perl6-Say
# Date created:				2007/07/28
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Perl6-Say
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl 6 say (print, but no newline needed) function

BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.07:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Test-Simple>=0.44:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Perl6::Say.3

.include <bsd.port.mk>
