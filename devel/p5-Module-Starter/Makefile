# Created by: clsung
# $FreeBSD$

PORTNAME=	Module-Starter
PORTVERSION=	1.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple starter kit for any Perl module

BUILD_DEPENDS=	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class

USES=		perl5
USE_PERL5=	configure

MAN1=		module-starter.1
MAN3=		Module::Starter.3 \
		Module::Starter::App.3 \
		Module::Starter::BuilderSet.3 \
		Module::Starter::Plugin.3 \
		Module::Starter::Plugin::Template.3 \
		Module::Starter::Simple.3

.include <bsd.port.mk>
