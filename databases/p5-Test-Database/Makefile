# New ports collection makefile for: 	p5-Test-Database
# Date created:				2 April, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Database
PORTVERSION=	1.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Database handles ready for testing

BUILD_DEPENDS=	${SITE_PERL}/mach/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Test/Builder/Module.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/YAML/Tiny.pm:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-File-HomeDir>=0.84:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-version>=0.76:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Database.3 Test::Database::Driver.3 \
		Test::Database::Driver::CSV.3 \
		Test::Database::Driver::DBM.3 \
		Test::Database::Driver::SQLite.3 \
		Test::Database::Driver::SQLite2.3 \
		Test::Database::Handle.3 \
		Test::Database::Util.3

.include <bsd.port.mk>
