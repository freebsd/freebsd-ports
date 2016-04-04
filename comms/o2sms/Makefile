# Created by: Conor McDermottroe <ports@mcdermottroe.com>
# $FreeBSD$

PORTNAME=	o2sms
PORTVERSION=	3.36
PORTREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN/WWW/MACKERS \
		http://www.mackers.com/projects/o2sms/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Send SMS messages via the websites of Irish mobile operators

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Lingua-EN-Squeeze>=0:textproc/p5-Lingua-EN-Squeeze \
		p5-TestGen4Web-Runner>=0:www/p5-TestGen4Web-Runner
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
