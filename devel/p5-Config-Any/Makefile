# New ports collection makefile for:	devel/p5-Config-Any
# Date created:				Sep 3, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Config-Any
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Load class configuration data from a number of file formats

RUN_DEPENDS=	p5-Module-Pluggable>=3.01:${PORTSDIR}/devel/p5-Module-Pluggable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Config::Any.3 \
	Config::Any::General.3 \
	Config::Any::INI.3 \
	Config::Any::JSON.3 \
	Config::Any::Perl.3 \
	Config::Any::XML.3 \
	Config::Any::YAML.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
