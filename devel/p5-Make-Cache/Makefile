# New ports collection makefile for:	p5-Make-Cache
# Date created:		2006-07-21
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Make-Cache
PORTVERSION=	1.041
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Make
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Caching of object and test run information

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		objcache.1
MAN3=		Make::Cache.3 \
		Make::Cache::Gcc.3 \
		Make::Cache::Hash.3 \
		Make::Cache::Obj.3 \
		Make::Cache::Runtime.3

.include <bsd.port.mk>
