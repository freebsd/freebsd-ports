# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	Sub-WrapPackages
PORTVERSION=	2.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Add pre- and post-execution wrappers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-Caller-IgnoreNamespaces>=1:${PORTSDIR}/devel/p5-Devel-Caller-IgnoreNamespaces \
		p5-Hook-LexWrap>=0:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-Sub-Prototype>=0.02:${PORTSDIR}/devel/p5-Sub-Prototype
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
