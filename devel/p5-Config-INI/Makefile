# Created by: bapt <baptiste.daroussin@gmail.com>
# $FreeBSD$

PORTNAME=	Config-INI
PORTVERSION=	0.020
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple .ini files emitter and parser for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS+=	p5-Mixin-Linewise>=0:${PORTSDIR}/devel/p5-Mixin-Linewise \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String

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
