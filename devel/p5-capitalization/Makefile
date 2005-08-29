# New ports collection makefile for:	capitalization.pm
# Date created:				29 August 2005
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	capitalization
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl module which allows you to use familiar style on method naming

BUILD_DEPENDS=	${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		capitalization.3

.include <bsd.port.mk>
