# New ports collection makefile for:	devel/p5-App-CLI
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-CLI
PORTVERSION=	0.313
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	App::CLI - Dispatcher module for command line interface programs

PERL_CONFIGURE=	yes

MAN3=		App::CLI.3 App::CLI::Command.3 App::CLI::Command::Help.3 App::CLI::Helper.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS=	p5-Getopt-Long>=2.35:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Locale-Maketext-Simple>0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Pod-Simple>0:${PORTSDIR}/textproc/p5-Pod-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
