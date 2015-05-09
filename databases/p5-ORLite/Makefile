# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	ORLite
PORTVERSION=	1.98
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 extremely light weight SQLite-specific ORM

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=1.27:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.60.7:${PORTSDIR}/databases/p5-DBI \
		p5-File-Remove>=1.40:${PORTSDIR}/devel/p5-File-Remove \
		p5-Params-Util>=0.33:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-XSAccessor>=0:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-Test-Script>=1.06:${PORTSDIR}/devel/p5-Test-Script

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
