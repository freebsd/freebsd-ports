# New ports collection makefile for:    p5-Test-Differences
# Date created:				January 28th 2003
# Whom:	      				Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Test-Differences
PORTVERSION=	0.46
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk
COMMENT=	Test::Differences - Test strings and data structures for differences

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Test::Differences.3

.include <bsd.port.mk>
