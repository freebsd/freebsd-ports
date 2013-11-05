# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-DBIC
PORTVERSION=	0.1803
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	DBIx::Class interface for Dancer applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class\
		p5-DBIx-Class-Schema-Loader>=0.07002:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader\
		p5-Dancer>=1.3098:${PORTSDIR}/www/p5-Dancer
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure
.include <bsd.port.mk>
