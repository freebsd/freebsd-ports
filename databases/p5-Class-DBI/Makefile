# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-DBI
PORTVERSION=	3.0.17
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple Database Abstraction

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Ima-DBI>=0:${PORTSDIR}/databases/p5-Ima-DBI \
		p5-UNIVERSAL-moniker>=0:${PORTSDIR}/devel/p5-UNIVERSAL-moniker \
		p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Class-Trigger>=0:${PORTSDIR}/devel/p5-Class-Trigger
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::DBI.3 Class::DBI::Attribute.3 \
		Class::DBI::Cascade::Delete.3 Class::DBI::Cascade::Fail.3 \
		Class::DBI::Cascade::None.3 Class::DBI::Column.3 \
		Class::DBI::ColumnGrouper.3 Class::DBI::Iterator.3 \
		Class::DBI::Query.3 Class::DBI::Relationship.3 \
		Class::DBI::SQL::Transformer.3 Class::DBI::Search::Basic.3 \
		Class::DBI::Test::SQLite.3

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
