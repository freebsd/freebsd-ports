# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-AuthorizedMethods
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Syntax sugar for authorized methods

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=1.21:${PORTSDIR}/devel/p5-Moose \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		MooseX::AuthorizedMethods.3 \
		MooseX::Meta::Method::Authorized.3 \
		MooseX::Meta::Method::Authorized::CheckRoles.3

.include <bsd.port.mk>
