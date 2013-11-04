# $FreeBSD$

PORTNAME=	Proc-Pidfile
PORTVERSION=	1.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for maintaining pid file for curent process

RUN_DEPENDS=	\
	p5-Proc-ProcessTable>0:${PORTSDIR}/devel/p5-Proc-ProcessTable
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
