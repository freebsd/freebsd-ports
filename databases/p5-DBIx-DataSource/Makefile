# New ports collection makefile for:	databases/p5-DBIx-DataSource
# Date created:				01 June 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-DataSource
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Database-independent create and drop functions

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN3=	DBIx::DataSource.3 DBIx::DataSource::Driver.3 \
	DBIx::DataSource::mysql.3 DBIx::DataSource::Pg.3

.include <bsd.port.mk>
