# New ports collection makefile for:	p5-Net-FTP-Common
# Date Created:				17 May, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FTP-Common
PORTVERSION=	4.0
CATEGORIES=	ftp perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/T/TB/TBONE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to provide simplify common usages of Net::FTP

BUILD_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

PERL_CONFIGURE=	yes

MAN3=		Net::FTP::Common.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${RM} ${WRKSRC}/lib/Net/FTP/Common.pm.orig

.include <bsd.port.mk>
