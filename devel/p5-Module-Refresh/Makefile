# New ports collection makefile for:	p5-Module-Refresh
# Date created:		13 February 2005
# Whom:	      		aturetta@commit.it
#
# $FreeBSD$
#

PORTNAME=	Module-Refresh
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsdports@commit.it
COMMENT=	Refresh %INC files when updated on disk

PERL_CONFIGURE=	yes

MAN3=		Module::Refresh.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
