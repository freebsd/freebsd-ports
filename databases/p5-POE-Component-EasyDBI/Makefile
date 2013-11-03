# Created by: Zach Thompson <lin-chi@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	POE-Component-EasyDBI
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE Component for simplified DBI usage

RUN_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
