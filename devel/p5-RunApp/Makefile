# New ports collection makefile for:	p5-RunApp
# Date created:				Dec 29 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	RunApp
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A generic module to run web-applications

BUILD_DEPENDS=	p5-App-Control>=0:${PORTSDIR}/devel/p5-App-Control \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
	
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		App::Control::Apache.3 \
		RunApp.3 \
		RunApp::Apache.3 \
		RunApp::Base.3 \
		RunApp::Control.3 \
		RunApp::Control::ApacheCtl.3 \
		RunApp::Control::AppControl.3 \
		RunApp::Cron.3 \
		RunApp::Template.3 \
		RunApp::Template::Apache.3

.include <bsd.port.mk>
