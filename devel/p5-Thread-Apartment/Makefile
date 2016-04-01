# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Thread-Apartment
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Apartment threading wrapper for Perl objects

LICENSE=	AFL21
LICENSE_NAME=	Academic Free License version 2.1
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	p5-Class-ISA>=0.32:devel/p5-Class-ISA \
		p5-Class-Inspector>=1.08:devel/p5-Class-Inspector \
		p5-Thread-Queue-Duplex>=0.92:devel/p5-Thread-Queue-Duplex
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
