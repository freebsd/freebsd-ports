# New ports collection makefile for:	p5-AppConfig
# Version required:			1.52
# Date created:				23 October 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

DISTNAME=	AppConfig-1.52
PKGNAME=	p5-AppConfig-1.52
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	App/ABW

MAINTAINER=	igor@zynaps.ru

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		AppConfig.3 \
		AppConfig::Sys.3 \
		AppConfig::File.3 \
		AppConfig::State.3 \
		AppConfig::Getopt.3 \
		AppConfig::Args.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
