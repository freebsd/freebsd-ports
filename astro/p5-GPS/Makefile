# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	GPS
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	astro perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-GPS-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl interface to GPS receivers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Device-SerialPort>=0.07:comms/p5-Device-SerialPort
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
