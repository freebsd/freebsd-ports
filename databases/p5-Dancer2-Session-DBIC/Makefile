# Created by: <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Session-DBIC
PORTVERSION=	0.110
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	DBIx::Class based session engine for Dancer2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class\
		p5-DBICx-Sugar>=0:databases/p5-DBICx-Sugar\
		p5-Dancer2>=0.200002:www/p5-Dancer2\
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Sereal-Decoder>=0:converters/p5-Sereal-Decoder\
		p5-Sereal-Encoder>=0:converters/p5-Sereal-Encoder\
		p5-DBIx-Class-TimeStamp>=0:databases/p5-DBIx-Class-TimeStamp\
		p5-DBICx-TestDatabase>=0:databases/p5-DBICx-TestDatabase

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
