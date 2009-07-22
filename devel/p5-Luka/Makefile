# New ports collection makefile for:	p5-Luka
# Date created:		2006-07-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Luka
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/T/TP/TPG
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Exception handling and reporting framework

RUN_DEPENDS=	${SITE_PERL}/Class/Std.pm:${PORTSDIR}/devel/p5-Class-Std \
		${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Mail/SendEasy.pm:${PORTSDIR}/mail/p5-Mail-SendEasy \
		${SITE_PERL}/Sub/Uplevel.pm:${PORTSDIR}/devel/p5-Sub-Uplevel \
		${SITE_PERL}/Sys/Hostname/Long.pm:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/What/MTA.pm:${PORTSDIR}/net/p5-What
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Luka.3 Luka::Conf.3 Luka::Exceptions.3 Luka::Mailer.3

.include <bsd.port.mk>
