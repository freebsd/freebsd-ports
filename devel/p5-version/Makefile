# New ports collection makefile for:	devel/p5-version
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	version
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/J/JP/JPEACOCK
PKGNAMEPREFIX=	p5-

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Perl extension for Version Objects

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		version.3 version::AlphaBeta.3

.include <bsd.port.mk>
