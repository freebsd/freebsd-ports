# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-DNS-ToolKit
PORTVERSION=	0.47
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tools for working with DNS packets

BUILD_DEPENDS=	p5-Net-DNS-Codes>=0.09:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		p5-NetAddr-IP>=1.30:${PORTSDIR}/net-mgmt/p5-NetAddr-IP
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
