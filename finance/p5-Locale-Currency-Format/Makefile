# New ports collection makefile for:	p5-Locale-Currency-Format
# Date Created:				27 Dec 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Locale-Currency-Format
PORTVERSION=	1.22
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Perl functions for formatting monetary values

PERL_CONFIGURE=	yes

MAN3=		Locale::Currency::Format.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
