# $FreeBSD$

PORTNAME=	carton
PORTVERSION=	1.0.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-
DISTNAME=	Carton-v${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module dependency manager

RUN_DEPENDS=	\
	p5-App-FatPacker>=0.009018:${PORTSDIR}/devel/p5-App-FatPacker \
	p5-App-cpanminus>=1.694:${PORTSDIR}/devel/p5-App-cpanminus \
	p5-CPAN-Meta>=2.120921:${PORTSDIR}/devel/p5-CPAN-Meta \
	p5-CPAN-Meta-Requirements>=2.121:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements \
	p5-Exception-Class>=1.32:${PORTSDIR}/devel/p5-Exception-Class \
	p5-File-pushd>0:${PORTSDIR}/devel/p5-File-pushd \
	p5-JSON>=2.53:${PORTSDIR}/converters/p5-JSON \
	p5-Module-CPANfile>=0.9031:${PORTSDIR}/devel/p5-Module-CPANfile \
	p5-Module-Metadata>=1.000003:${PORTSDIR}/devel/p5-Module-Metadata \
	p5-Module-Reader>=0.002:${PORTSDIR}/devel/p5-Module-Reader \
	p5-Moo>=1.002:${PORTSDIR}/devel/p5-Moo \
	p5-Path-Tiny>=0.033:${PORTSDIR}/devel/p5-Path-Tiny \
	p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
