# New ports collection makefile for:	devel/p5-Module-Starter
# Date created:				March 15 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Starter
PORTVERSION=	1.38
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A simple starter kit for any Perl module

PERL_CONFIGURE=	yes

MAN1=		module-starter.1
MAN3=		Module::Starter.3 \
		Module::Starter::Simple.3 \
		Module::Starter::Plugin.3 \
		Module::Starter::Plugin::Template.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
