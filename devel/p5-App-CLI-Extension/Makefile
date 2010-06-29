# New ports collection makefile for:	p5-App-CLI-Extension
# Date created:				5th Jan, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-CLI-Extension
PORTVERSION=	1.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extension for App::CLI extension module

BUILD_DEPENDS=	p5-App-CLI>=0:${PORTSDIR}/devel/p5-App-CLI \
		p5-Class-Data-Accessor>=0:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	App::CLI::Extension::Component::RunCommand.3 \
	App::CLI::Extension::Component::ErrorHandler.3 \
	App::CLI::Extension::Component::OriginalArgv.3 \
	App::CLI::Extension::Component::InstallCallback.3 \
	App::CLI::Extension.3 \
	App::CLI::Extension::Component::Config.3 \
	App::CLI::Extension::Component::Stash.3

.include <bsd.port.mk>
