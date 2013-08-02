# New ports collection makefile for:	devel/p5-CPAN-YACSmoke
# Date created:				3 March 2005
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CPAN-YACSmoke
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another CPAN Smoke Tester

RUN_DEPENDS=	p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-File-HomeDir>=0.06:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-Regexp-Assemble>=0.06:${PORTSDIR}/devel/p5-Regexp-Assemble \
		p5-Sort-Versions>=1.5:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-Test-Reporter>=1.25:${PORTSDIR}/devel/p5-Test-Reporter \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		CPAN::YACSmoke.3 \
		CPAN::YACSmoke::Plugin::SmokeDB.3 \
		CPAN::YACSmoke::Plugin::Recent.3

.include <bsd.port.mk>
