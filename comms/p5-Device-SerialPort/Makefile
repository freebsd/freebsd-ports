# New ports collection makefile for:    p5-Device-SerialPort
# Date created:				July 6th 2003
# Whom:	      				Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Device-SerialPort
PORTVERSION=	1.002
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Device
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A perl5 module for simple serial port control

PERL_CONFIGURE=	yes

MAN1=		modemtest.1
MAN3=		Device::SerialPort.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Perl 5.6 or newer required. Install lang/perl5.8 or lang/perl5 and try again.
.endif

.include <bsd.port.post.mk>
