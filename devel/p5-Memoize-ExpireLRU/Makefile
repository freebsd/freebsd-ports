# New ports collection makefile for:	devel/p5-Memoize-ExpireLRU
# Date created:				Mon Jan 12 11:40:14 CST 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Memoize-ExpireLRU
PORTVERSION=	0.55
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Memoize
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration

BUILD_DEPENDS=	${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Memoize::ExpireLRU.3

.include <bsd.port.mk>
