# New ports collection makefile for:	p5-AppConfig
# Date created:				23 October 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	AppConfig
PORTVERSION=	1.63
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Perl module for reading configuration files

RUN_DEPENDS=	p5-File-HomeDir>=0.57:${PORTSDIR}/devel/p5-File-HomeDir
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		AppConfig.3 \
		AppConfig::Args.3 \
		AppConfig::CGI.3 \
		AppConfig::File.3 \
		AppConfig::Getopt.3 \
		AppConfig::State.3 \
		AppConfig::Sys.3

.include <bsd.port.mk>
