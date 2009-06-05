# New ports collection makefile for:	p5-usb
# Date created:		2007-05-05
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	usb
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Device \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
PKGNAMEPREFIX=	p5-
DISTNAME=	Device-USB-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Perl wrapper for libusb

LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
BUILD_DEPENDS=	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline

WRKSRC=		${WRKDIR}/Device-USB-${PORTVERSION}
PERL_CONFIGURE=	yes

MAN3=		Device::USB.3 \
		Device::USB::Bus.3 \
		Device::USB::DevConfig.3 \
		Device::USB::DevEndpoint.3 \
		Device::USB::DevInterface.3 \
		Device::USB::Device.3 \
		Device::USB::FAQ.3 \
		Device::dump_usb.3

.include <bsd.port.mk>
