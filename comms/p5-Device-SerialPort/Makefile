# New ports collection makefile for:    p5-Device-SerialPort
# Date created:				July 6th 2003
# Whom:	      				Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Device-SerialPort
PORTVERSION=	0.22
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Device
PKGNAMEPREFIX=	p5-
DISTNAME=	Device-SerialPort-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 module for simple serial port control

PERL_CONFIGURE=	yes

MAN3=		Device::SerialPort.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		"needs at least perl 5.6.1 to build"
.endif

.include <bsd.port.post.mk>
