# New ports collection makefile for:  Gravatar-URL
# Date created: 23 December 2009
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Gravatar-URL
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MS/MSCHWERN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Make URLs for Gravatars from an email address

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.0+
PERL_MODBUILD=yes

MAN3=	Gravatar::URL.3 Unicornify::URL.3

.include <bsd.port.mk>
