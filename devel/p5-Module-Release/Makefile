# New ports collection makefile for:	release
# Date created:	   14 Mart 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Module-Release
PORTVERSION=	2.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Upload files to CPAN and SourceForge

BUILD_DEPENDS=	p5-CACertOrg-CA>=0:${PORTSDIR}/security/p5-CACertOrg-CA \
		p5-ConfigReader-Simple>=0:${PORTSDIR}/devel/p5-ConfigReader-Simple \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-Null>=0:${PORTSDIR}/devel/p5-IO-Null \
		p5-LWP-Protocol-https>=6.02:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=6.02:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Without-Module>=0:${PORTSDIR}/devel/p5-Test-Without-Module

USE_PERL5=	configure
USES=		perl5

MAN1=		release.1
MAN3=		Module::Release.3 \
		Module::Release::FTP.3 \
		Module::Release::Kwalitee.3 \
		Module::Release::MANIFEST.3 \
		Module::Release::PAUSE.3 \
		Module::Release::Prereq.3 \
		Module::Release::SVN.3 \
		Module::Release::SourceForge.3

.include <bsd.port.mk>
