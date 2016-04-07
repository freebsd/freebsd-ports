# Created by: <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-DBIC
PORTVERSION=	0.0012
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	DBIx::Class interface for Dancer2 applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class\
		p5-DBIx-Class-Schema-Loader>=0.07002:databases/p5-DBIx-Class-Schema-Loader\
		p5-DBICx-Sugar>=0:databases/p5-DBICx-Sugar\
		p5-Dancer2>=0.153002:www/p5-Dancer2
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
