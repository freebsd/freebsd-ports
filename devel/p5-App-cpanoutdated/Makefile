# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	App-cpanoutdated
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect outdated CPAN modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CPAN-DistnameInfo>=0.10:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-local-lib>=0:${PORTSDIR}/devel/p5-local-lib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN1=		cpan-outdated.1
MAN3=		App::cpanoutdated.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-Module-Metadata>=1.000007:${PORTSDIR}/devel/p5-Module-Metadata
RUN_DEPENDS+=	p5-Module-Metadata>=1.000007:${PORTSDIR}/devel/p5-Module-Metadata
.endif

.include <bsd.port.post.mk>
