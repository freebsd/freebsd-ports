# New ports collection makefile for:	p5-Net-FTP-Recursive
# Date Created:				11 April, 2005
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FTP-Recursive
PORTVERSION=	2.02
CATEGORIES=	ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to provide recursive FTP client class

BUILD_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

WRKSRC=		${WRKDIR}/${PORTNAME}

PERL_CONFIGURE=	yes

MAN3=		Net::FTP::Recursive.3

.include <bsd.port.mk>
