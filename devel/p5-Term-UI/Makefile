# New ports collection makefile for:	p5-Term-UI
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Term-UI
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Term::ReadLine UI made easy

BUILD_DEPENDS=	${SITE_PERL}/Params/Check.pm:${PORTSDIR}/devel/p5-Params-Check \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/Log/Message/Simple.pm:${PORTSDIR}/devel/p5-Log-Message-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Term::UI.3 Term::UI::History.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
