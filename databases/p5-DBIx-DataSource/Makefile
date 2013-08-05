# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	DBIx-DataSource
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Database-independent create and drop functions

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::DataSource.3 DBIx::DataSource::Driver.3 \
	DBIx::DataSource::mysql.3 DBIx::DataSource::Pg.3

.include <bsd.port.mk>
