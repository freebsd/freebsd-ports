# New ports collection makefile for:	p5-Device-Modem
# Date created:				22 July 2003
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Device-Modem
PORTVERSION=	1.28
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Device
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl class to interface generic modems (AT-compliant)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Device/SerialPort.pm:${PORTSDIR}/comms/p5-Device-SerialPort
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Device::Modem::Log::File.3 Device::Modem::Log::Syslog.3 Device::Modem.3

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/active.pl ${DOCSDIR}/examples/
	${INSTALL_DATA} ${WRKSRC}/examples/dial.pl ${DOCSDIR}/examples/
	${INSTALL_DATA} ${WRKSRC}/examples/shell.pl ${DOCSDIR}/examples/
.endif

.include <bsd.port.mk>
