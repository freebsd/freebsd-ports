# New ports collection makefile for:	p5-AppConfig
# Date created:				23 October 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	AppConfig
PORTVERSION=	1.56
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	App/ABW
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	A Perl module for reading configuration files

PERL_CONFIGURE=	YES

MAN3=		AppConfig.3 \
		AppConfig::Args.3 \
		AppConfig::CGI.3 \
		AppConfig::File.3 \
		AppConfig::Getopt.3 \
		AppConfig::State.3 \
		AppConfig::Sys.3

post-patch:
	${PERL} -pi -e '$$_="" if /use warnings/;' \
		${WRKSRC}/t/*.t

.include <bsd.port.mk>
