# New ports collection makefile for:	p5-Make-Cache
# Date created:		2006-07-21
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Make-Cache
PORTVERSION=	1.051
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Caching of object and test run information

BUILD_DEPENDS=	p5-BSD-Resource>=0:${PORTSDIR}/devel/p5-BSD-Resource

PERL_CONFIGURE=	yes

MAN1=		objcache.1
MAN3=		Make::Cache.3 \
		Make::Cache::Gcc.3 \
		Make::Cache::Hash.3 \
		Make::Cache::Obj.3 \
		Make::Cache::Runtime.3

.include <bsd.port.mk>
