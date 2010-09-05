# New ports collection makefile for:	p5-Config-YAML
# Date created:		2010-03-03
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Config-YAML
PORTVERSION=	1.42
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Simple configuration automation

BUILD_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	5.8.3+

MAN3=	Config::YAML.3

.include <bsd.port.mk>
