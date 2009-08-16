# New ports collection makefile for:	devel/p5-Config-Any
# Date created:				Sep 3, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Config-Any
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load class configuration data from a number of file formats

RUN_DEPENDS=	p5-Module-Pluggable>=3.01:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-version>=0:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Config::Any.3 \
	Config::Any::Base.3 \
	Config::Any::General.3 \
	Config::Any::INI.3 \
	Config::Any::JSON.3 \
	Config::Any::Perl.3 \
	Config::Any::XML.3 \
	Config::Any::YAML.3

.include <bsd.port.mk>
