# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Depends
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Identify the dependencies of a distribution

RUN_DEPENDS=	p5-Class-Accessor-Chained>=0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Module::Depends::Intrusive.3 Module::Depends.3

.include <bsd.port.mk>
