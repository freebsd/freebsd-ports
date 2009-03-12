# New ports collection makefile for:	p5-Config-INI
# Date created:		2009-03-10
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Config-INI
PORTVERSION=	0.014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Simple .ini files emitter and parser for Perl

BUILD_DEPENDS=	${SITE_PERL}/Mixin/Linewise/Readers.pm:${PORTSDIR}/devel/p5-Mixin-Linewise

RUN_DEPENDS+=	${SITE_PERL}/Mixin/Linewise/Readers.pm:${PORTSDIR}/devel/p5-Mixin-Linewise

PERL_CONFIGURE=	yes

MAN3=		Config::INI.3 \
		Config::INI::Reader.3 \
		Config::INI::Writer.3

PLIST_FILES=	%%SITE_PERL%%/Config/INI.pm \
		%%SITE_PERL%%/Config/INI/Reader.pm \
		%%SITE_PERL%%/Config/INI/Writer.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Config/INI/.packlist
PLIST_DIRS=	%%SITE_PERL%%/Config/INI \
		%%SITE_PERL%%/Config \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Config/INI \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Config

.include <bsd.port.mk>
