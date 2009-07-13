# New ports collection makefile for:	databases/p5-DBIx-Class-Validation
# Date created:				03 Aug 2007
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Validation
PORTVERSION=	0.02005
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Validate data before submitting to a database

BUILD_DEPENDS=	${SITE_PERL}/Module/Install.pm:${PORTSDIR}/devel/p5-Module-Install \
		${SITE_PERL}/DateTime/Format/Builder.pm:${PORTSDIR}/devel/p5-DateTime-Format-SQLite \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
		p5-FormValidator-Simple>=0.17:${PORTSDIR}/textproc/p5-FormValidator-Simple \
		p5-DBD-SQLite>=1.11:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.07005:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	DBIx::Class::Validation.3

.include <bsd.port.mk>
