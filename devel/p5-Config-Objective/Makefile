# Created by: Jim Pirzyk <pirzyk@uiuc.edu>
# $FreeBSD$

PORTNAME=	Config-Objective
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Configuration data as perl objects

BUILD_DEPENDS=	p5-Parse-Yapp>=0:${PORTSDIR}/devel/p5-Parse-Yapp \
		p5-ParseLex>=0:${PORTSDIR}/devel/p5-ParseLex
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Config::Objective::List.3 Config::Objective::Boolean.3 \
		Config::Objective::Table.3 Config::Objective.3 \
		Config::Objective::Hash.3 Config::Objective::Integer.3 \
		Config::Objective::String.3 Config::Objective::DataType.3

.include <bsd.port.mk>
