# Created by: <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Interchange6-Schema
PORTVERSION=	0.133
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HORNBURG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Database Schema for Interchange 6

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class\
		p5-DBIx-Class-Schema-Config>=0:databases/p5-DBIx-Class-Schema-Config\
		p5-DBIx-Class-PassphraseColumn>=0:databases/p5-DBIx-Class-PassphraseColumn\
		p5-DBIx-Class-InflateColumn-Authen-Passphrase>=0:databases/p5-DBIx-Class-InflateColumn-Authen-Passphrase\
		p5-DBIx-Class-Tree>=0:databases/p5-DBIx-Class-Tree\
		p5-Data-UUID>=0:devel/p5-Data-UUID\
		p5-Time-Duration-Parse>=0:devel/p5-Time-Duration-Parse\
		p5-Locale-SubCountry>=0:misc/p5-Locale-SubCountry\
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite\
		p5-DBIx-Class-TimeStamp>=0:databases/p5-DBIx-Class-TimeStamp\
		p5-DBIx-Class-Helpers>=0:databases/p5-DBIx-Class-Helpers\
		p5-Test-Warnings>=0:devel/p5-Test-Warnings\
		p5-Test-Roo>=0:devel/p5-Test-Roo\
		p5-DBICx-TestDatabase>=0:databases/p5-DBICx-TestDatabase

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
