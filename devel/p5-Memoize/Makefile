# $FreeBSD$

PORTNAME=	Memoize
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MJD
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Transparently speed up perl functions by caching return values

USES=		perl5
USE_PERL5=	configure

MAN3=		Memoize.3 \
		Memoize::AnyDBM_File.3 \
		Memoize::Expire.3 \
		Memoize::ExpireFile.3 \
		Memoize::ExpireTest.3 \
		Memoize::NDBM_File.3 \
		Memoize::SDBM_File.3 \
		Memoize::Storable.3

NO_STAGE=	yes
.include <bsd.port.mk>
