# New ports collection makefile for:	Iterator-Misc
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Iterator-Misc
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Iterator
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Miscellaneous iterator functions

BUILD_DEPENDS=	${SITE_PERL}/Iterator.pm:${PORTSDIR}/devel/p5-Iterator
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Iterator::Misc.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl5.8 due to dependencies
.endif

.include <bsd.port.post.mk>
