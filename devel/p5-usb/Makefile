# New ports collection makefile for:	p5-usb
# Date created:		2007-05-05
# Whom:			Jason Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	usb
PORTVERSION=	0.21
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/G/GW/GWADEJ/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
PKGNAMEPREFIX=	p5-
DISTNAME=	Device-USB-${PORTVERSION}

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Perl wrapper for libusb

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/5.8.8/Inline.pm:${PORTSDIR}/devel/p5-Inline
LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

WRKSRC=		${WRKDIR}/Device-USB-0.21
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
