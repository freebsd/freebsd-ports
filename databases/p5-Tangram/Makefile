# New ports collection makefile for:	Tangram
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Tangram
PORTVERSION=	2.07
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tangram
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Orthogonal Object Persistence in Relational Databases

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Set/Object.pm:${PORTSDIR}/devel/p5-Set-Object \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tangram.3 Tangram::Array.3 Tangram::Core.3 Tangram::Cursor.3 \
		Tangram::DateTime.3 Tangram::Deploy.3 Tangram::Dialect.3 \
		Tangram::Expr.3 Tangram::FlatArray.3 Tangram::FlatHash.3 \
		Tangram::IntrArray.3 Tangram::IntrSet.3 Tangram::PerlDump.3 \
		Tangram::Ref.3 Tangram::Relational.3 \
		Tangram::Relational::Mappings.3 Tangram::Remote.3 \
		Tangram::Scalar.3 Tangram::Schema.3 Tangram::Set.3 \
		Tangram::Springfield.3 Tangram::Storage.3 Tangram::Sybase.3 \
		Tangram::Tour.3 Tangram::Type.3 Tangram::Type::Extending.3 \
		Tangram::mysql.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
