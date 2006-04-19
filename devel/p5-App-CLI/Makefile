# New ports collection makefile for:	devel/p5-App-CLI
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-CLI
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	App
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	App::CLI - Dispatcher module for command line interface programs

BUILD_DEPENDS=	\
		p5-Locale-Maketext-Simple>0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Pod-Simple>0:${PORTSDIR}/textproc/p5-Pod-Simple \
		p5-Getopt-Long>=2.34:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	App::CLI.3 \
	App::CLI::Command.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
