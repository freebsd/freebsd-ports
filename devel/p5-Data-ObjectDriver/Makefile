# New ports collection makefile for:	p5-Data-ObjectDriver
# Date created:		2007-02-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Data-ObjectDriver
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Simple, transparent data interface, with caching

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Trigger.pm:${PORTSDIR}/devel/p5-Class-Trigger \
		${SITE_PERL}/Text/SimpleTable.pm:${PORTSDIR}/textproc/p5-Text-SimpleTable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::ObjectDriver.3 Data::ObjectDriver::BaseObject.3 \
		Data::ObjectDriver::Driver::DBD::SQLite.3 \
		Data::ObjectDriver::Profiler.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
