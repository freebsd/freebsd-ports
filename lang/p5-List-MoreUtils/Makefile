# New ports collection makefile for:	lang/p5-List-MoreUtils
# Date created:				24 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	List-MoreUtils
PORTVERSION=	0.13
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	List
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Provide the stuff missing in List::Util

PERL_CONFIGURE=	yes

MAN3=	List::MoreUtils.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
