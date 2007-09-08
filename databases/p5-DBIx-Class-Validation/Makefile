# New ports collection makefile for:	databases/p5-DBIx-Class-Validation
# Date created:				03 Aug 2007
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Validation
PORTVERSION=	0.02000
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Validate data before submitting to a database

BUILD_DEPENDS=	${SITE_PERL}/Module/Install.pm:${PORTSDIR}/devel/p5-Module-Install \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
		${SITE_PERL}/FormValidator/Simple.pm:${PORTSDIR}/textproc/p5-FormValidator-Simple \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/DBIx/Class.pm:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	DBIx::Class::Validation.3

.include <bsd.port.mk>
