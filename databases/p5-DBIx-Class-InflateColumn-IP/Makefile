# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-InflateColumn-IP
PORTVERSION=	0.02003
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Component to auto-create NetAddr::IP objects from columns

BUILD_DEPENDS=	p5-DBIx-Class>=0.06002:databases/p5-DBIx-Class \
		p5-NetAddr-IP>=4.00.7:net-mgmt/p5-NetAddr-IP
RUN_DEPENDS=	p5-DBIx-Class>=0.06002:databases/p5-DBIx-Class \
		p5-NetAddr-IP>=4.00.7:net-mgmt/p5-NetAddr-IP
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
