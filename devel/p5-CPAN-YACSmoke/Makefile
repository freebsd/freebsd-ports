# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-YACSmoke
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Yet Another CPAN Smoke Tester

RUN_DEPENDS=	p5-Config-IniFiles>=0:devel/p5-Config-IniFiles \
		p5-File-HomeDir>=0.06:devel/p5-File-HomeDir \
		p5-Regexp-Assemble>=0.06:devel/p5-Regexp-Assemble \
		p5-Sort-Versions>=1.5:devel/p5-Sort-Versions \
		p5-Test-Reporter>=1.25:devel/p5-Test-Reporter \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
