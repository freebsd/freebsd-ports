# New ports collection makefile for:	databases/p5-DBIx-DBSchema
# Date created:				21 September 2002
# Whom:					Peter Avalos <pavalos@theshell.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-DBSchema
PORTVERSION=	0.21
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	DBIx::DBSchema.3 DBIx::DBSchema::ColGroup.3 \
	DBIx::DBSchema::ColGroup::Index.3 DBIx::DBSchema::ColGroup::Unique.3 \
	DBIx::DBSchema::Column.3 DBIx::DBSchema::DBD.3 \
	DBIx::DBSchema::DBD::mysql.3 DBIx::DBSchema::DBD::Pg.3 \
	DBIx::DBSchema::DBD::Sybase.3 DBIx::DBSchema::Table.3

.include <bsd.port.mk>
