# New ports collection makefile for:   Scope-Guard
# Date created:           29 December 2006
# Whom:                   Craig Manley
#
# $FreeBSD$
#

PORTNAME=	Scope-Guard
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
#MASTER_SITE_SUBDIR=   Scope
MASTER_SITE_SUBDIR=	../by-authors/id/C/CH/CHOCOLATE
PKGNAMEPREFIX=	p5-

MAINTAINER=	cmanley@xs4all.nl
COMMENT=	Lexically scoped resource management

PERL_CONFIGURE=	yes

MAN3=		Scope::Guard.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or later
.endif

.include <bsd.port.post.mk>
