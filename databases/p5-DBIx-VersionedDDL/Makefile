# New ports collection makefile for:	p5-DBIx-VersionedDDL
# Date created:			30 December 2009
# Whom:				alan
#
# $FreeBSD$
#

PORTNAME=	DBIx-VersionedDDL
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alan@Wave2.org
COMMENT=	Upgrade and downgrade database schemas to a specified version

RUN_DEPENDS=	p5-DBD-SQLite>=1.27:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
		p5-Text-CSV>=1.16:${PORTSDIR}/textproc/p5-Text-CSV

PERL_CONFIGURE=	5.8.8+

MAN1=	migrate_schema.1
MAN3=	DBIx::VersionedDDL.3

.include <bsd.port.mk>
