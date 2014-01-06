# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	AnyEvent-DBI
PORTVERSION=	2.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	AnyEvent::DBI - asynchronous DBI access

BUILD_DEPENDS=	p5-AnyEvent>=4.15:${PORTSDIR}/devel/p5-AnyEvent \
		p5-DBI>=1.0:${PORTSDIR}/databases/p5-DBI \
		p5-common-sense>=3.3:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
