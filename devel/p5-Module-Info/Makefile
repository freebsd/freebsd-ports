# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Info
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Provides information about Perl modules

BUILD_DEPENDS=	p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		module_info.1 pfunc.1
MAN3=		B::BUtils.3 B::Module::Info.3 Module::Info.3

.include <bsd.port.mk>
