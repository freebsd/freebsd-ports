# Ports collection makefile for:	devel-p5-Cache-AgainstFile
# Date created:				10 April 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=		Cache-AgainstFile
PORTVERSION=		1.016
CATEGORIES=		devel perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=		p5-

MAINTAINER=		freebsdports@chillibear.com
COMMENT=		Cache data structures parsed from files, watching for updates

RUN_DEPENDS=	p5-Log-Trace>0:${PORTSDIR}/devel/p5-Log-Trace \
	p5-Test-Assertions>0:${PORTSDIR}/devel/p5-Test-Assertions
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Cache::AgainstFile::Memory.3 \
	Cache::AgainstFile.3 \
	Cache::AgainstFile::Storable.3 \
	Cache::AgainstFile::Null.3 \
	Cache::AgainstFile::Base.3 \
	Cache::AgainstFile::CacheModule.3

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
