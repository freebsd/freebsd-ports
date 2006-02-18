# New ports collection makefile for:	Iterator
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Iterator
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROODE
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A general-purpose iterator class

BUILD_DEPENDS=	${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class

MAN3=	Iterator.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl5.8
.endif

.include <bsd.port.post.mk>
