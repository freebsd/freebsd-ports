# New ports collection makefile for: DBIx::SQLEngine
# Date created:   31.7.2003
# Whom:           Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SQLEngine
PORTVERSION=	0.009
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	hansjoerg.pehofer@uibk.ac.at
COMMENT=	Extends DBI with high-level operations

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/DBIx/AnyDBD.pm:${PORTSDIR}/databases/p5-DBIx-AnyDBD \
		${SITE_PERL}/Class/MakeMethods/Template.pm:${PORTSDIR}/devel/p5-Class-MakeMethods
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MAN3=	DBIx::SQLEngine::Criteria::StringEquality.3\
		DBIx::Changes.3\
		DBIx::SQLEngine::Criteria::Or.3\
		DBIx::SQLEngine::Criteria::And.3\
		DBIx::SQLEngine::ToDo.3\
		DBIx::SQLEngine::ReadMe.3\
		DBIx::SQLEngine::Criteria.3\
		DBIx::SQLEngine::Criteria::Compound.3\
		DBIx::SQLEngine::Criteria::NumericLesser.3\
		DBIx::SQLEngine::Criteria::Comparison.3\
		DBIx::SQLEngine::Criteria::Not.3\
		DBIx::SQLEngine::Changes.3\
		DBIx::SQLEngine::Criteria::LiteralSQL.3\
		DBIx::SQLEngine::Mixin::SeqTable.3\
		DBIx::SQLEngine.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
