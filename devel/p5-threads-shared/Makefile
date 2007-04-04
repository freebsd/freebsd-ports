# New ports collection makefile for:	p5-threads-shared
# Date created:		2007-03-18
# Whom:			Ruben van Staveren
#
# $FreeBSD$
#

PORTNAME=	threads-shared
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/J/JD/JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ruben@verweg.com
COMMENT=	Perl extension for sharing data structures between threads

RUN_DEPENDS=	p5-threads>=1.59:${PORTSDIR}/devel/p5-threads
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	threads::shared.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
