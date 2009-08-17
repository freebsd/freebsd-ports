# New ports collection makefile for:	release
# Date created:	   14 Mart 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Module-Release
PORTVERSION=	2.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Upload files to CPAN and SourceForge

BUILD_DEPENDS=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/IO/Null.pm:${PORTSDIR}/devel/p5-IO-Null \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/ConfigReader/Simple.pm:${PORTSDIR}/devel/p5-ConfigReader-Simple \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/HTTP/Message.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		release.1
MAN3=		Module::Release.3 Module::Release::FTP.3 Module::Release::Kwalitee.3 \
		Module::Release::PAUSE.3 Module::Release::Prereq.3 Module::Release::SVN.3

.include <bsd.port.mk>
