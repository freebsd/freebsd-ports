# New ports collection makefile for:	p5-Hook-LexWrap
# Date created:				Wed Jul 7 2004
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Hook-LexWrap
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Hook
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lexically scoped subroutine wrappers for Perl

PERL_CONFIGURE=	yes

MAN3=		Hook::LexWrap.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port only support perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
