# New ports collection makefile for:	p5-usb
# Date created:		2007-05-05
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	Device-USB
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
PKGNAMEPREFIX=	p5-

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Perl wrapper for libusb

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline

MAKE_JOBS_UNSAFE=yes
PERL_CONFIGURE=	yes

MAN3=		Device::USB.3 \
		Device::USB::Bus.3 \
		Device::USB::DevConfig.3 \
		Device::USB::DevEndpoint.3 \
		Device::USB::DevInterface.3 \
		Device::USB::Device.3 \
		Device::USB::FAQ.3 \
		Device::dump_usb.3

.include <bsd.port.pre.mk>

# libusb is in base for newer releases
.if ${OSVERSION} < 800069
LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

.include <bsd.port.post.mk>
