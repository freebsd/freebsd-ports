# New ports collection makefile for:	devel/p5-Perl6-Rules
# Date created:				2007/07/28
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Perl6-Rules
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implements (most of) the Perl 6 regex syntax

BUILD_DEPENDS=	p5-Attribute-Handlers>=0:${PORTSDIR}/devel/p5-Attribute-Handlers \
		p5-Filter-Simple>=0:${PORTSDIR}/textproc/p5-Filter-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Perl6::Rules.3

.include <bsd.port.mk>
