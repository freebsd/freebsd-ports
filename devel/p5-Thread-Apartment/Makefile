# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Thread-Apartment
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Apartment threading wrapper for Perl objects

RUN_DEPENDS=	p5-Thread-Queue-Duplex>=0.92:${PORTSDIR}/devel/p5-Thread-Queue-Duplex \
		p5-Class-ISA>=0.32:${PORTSDIR}/devel/p5-Class-ISA \
		p5-Class-Inspector>=1.08:${PORTSDIR}/devel/p5-Class-Inspector
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Thread::Apartment.3

NO_STAGE=	yes
.include <bsd.port.mk>
