# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-DBI-Lite
PORTVERSION=	1.034
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight ORM for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Cache-Memcached>=1.27:${PORTSDIR}/databases/p5-Cache-Memcached \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Ima-DBI-Contextual>=1.005:${PORTSDIR}/databases/p5-Ima-DBI-Contextual \
		p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract \
		p5-SQL-Abstract-Limit>=0:${PORTSDIR}/databases/p5-SQL-Abstract-Limit
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

DEPRECATED=	deprecated by upstream

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
