# New ports collection makefile for:	p5-Net-FTPSSL
# Date created:				1st Dec, 2010
# Whom:	      				Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FTPSSL
PORTVERSION=	0.19
CATEGORIES=	ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A FTP over SSL/TLS class

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.08:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::FTPSSL.3

.include <bsd.port.mk>
