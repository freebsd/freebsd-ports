# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	DBIx-Class-Schema-Config
PORTVERSION=	0.001008
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Credential Management for DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Any>=0.23:${PORTSDIR}/devel/p5-Config-Any \
		p5-DBIx-Class>=0.08100:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-File-HomeDir>0:${PORTSDIR}/devel/p5-File-HomeDir
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Config-Any>=0.23:${PORTSDIR}/devel/p5-Config-Any \
		p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-MockObject>=1.09:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

MAN3=		DBIx::Class::Schema::Config.3

.include <bsd.port.mk>
