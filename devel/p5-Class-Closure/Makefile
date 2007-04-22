# New ports collection makefile for:	devel/p5-Class-Closure
# Date created:				22 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Closure
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Encapsulated, declarative classes in Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker \
		${SITE_PERL}/${PERL_ARCH}/Devel/Caller.pm:${PORTSDIR}/devel/p5-Devel-Caller
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::Closure.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		depends on something that wants perl 5.8.0 or later
.endif

.include <bsd.port.post.mk>
