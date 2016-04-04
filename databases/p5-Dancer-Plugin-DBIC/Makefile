# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-DBIC
PORTVERSION=	0.2104
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DBIx::Class interface for Dancer applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class\
		p5-DBIx-Class-Schema-Loader>=0.07002:databases/p5-DBIx-Class-Schema-Loader\
		p5-Dancer>=1.3098:www/p5-Dancer \
		p5-DBICx-Sugar>=0:databases/p5-DBICx-Sugar \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Requires>=0:devel/p5-Test-Requires
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Temp>=0:devel/p5-File-Temp \
		p5-Module-Load-Conditional>=0.38:devel/p5-Module-Load-Conditional \
		p5-MooseX-Types-LoadableClass>0:devel/p5-MooseX-Types-LoadableClass

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
