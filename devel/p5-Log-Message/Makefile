# New ports collection makefile for:	p5-Log-Message
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Message
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Powerful and flexible message logging mechanism

BUILD_DEPENDS=	${SITE_PERL}/Params/Check.pm:${PORTSDIR}/devel/p5-Params-Check \
		${SITE_PERL}/Module/Load.pm:${PORTSDIR}/devel/p5-Module-Load \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Log::Message.3 \
	Log::Message::Config.3 \
	Log::Message::Handlers.3 \
	Log::Message::Item.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
