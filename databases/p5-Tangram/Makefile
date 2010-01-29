# New ports collection makefile for:	Tangram
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Tangram
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Orthogonal Object Persistence in Relational Databases

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Set/Object.pm:${PORTSDIR}/devel/p5-Set-Object \
		${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece \
		${SITE_PERL}/${PERL_ARCH}/Class/Date.pm:${PORTSDIR}/devel/p5-Class-Date \
		${SITE_PERL}/Data/Lazy.pm:${PORTSDIR}/devel/p5-Data-Lazy \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Tangram.3 \
	Tangram::Complicity.3 \
	Tangram::Core.3 \
	Tangram::Cursor.3 \
	Tangram::Deploy.3 \
	Tangram::Driver::Oracle.3 \
	Tangram::Driver::Pg.3 \
	Tangram::Driver::SQLite.3 \
	Tangram::Driver::Sybase.3 \
	Tangram::Driver::mysql.3 \
	Tangram::Expr.3 \
	Tangram::Intro.3 \
	Tangram::Relational.3 \
	Tangram::Relational::Mappings.3 \
	Tangram::Remote.3 \
	Tangram::Schema.3 \
	Tangram::Springfield.3 \
	Tangram::Storage.3 \
	Tangram::Sucks.3 \
	Tangram::Tour.3 \
	Tangram::Type.3 \
	Tangram::Type::Array::FromMany.3 \
	Tangram::Type::Array::FromOne.3 \
	Tangram::Type::Array::Scalar.3 \
	Tangram::Type::Dump.3 \
	Tangram::Type::Dump::Any.3 \
	Tangram::Type::Dump::Perl.3 \
	Tangram::Type::Dump::Storable.3 \
	Tangram::Type::Dump::YAML.3 \
	Tangram::Type::Extending.3 \
	Tangram::Type::Hash::Scalar.3 \
	Tangram::Type::Ref::FromMany.3 \
	Tangram::Type::Scalar.3 \
	Tangram::Type::Set::FromMany.3 \
	Tangram::Type::Set::FromOne.3 \
	Tangram::Type::TimeAndDate.3

.include <bsd.port.mk>
