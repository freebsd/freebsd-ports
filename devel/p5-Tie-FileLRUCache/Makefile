# New ports collection makefile for:	devel/p5-Tie-FileLRUCache
# Date created:				Oct 23 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Tie-FileLRUCache
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A lightweight but robust filesystem based persistent LRU cache

BUILD_DEPENDS=	${SITE_PERL}/Class/NamedParms.pm:${PORTSDIR}/devel/p5-Class-NamedParms \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Class/ParmList.pm:${PORTSDIR}/devel/p5-Class-ParmList
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tie::FileLRUCache.3

.include <bsd.port.mk>
