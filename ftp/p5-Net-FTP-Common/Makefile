# New ports collection makefile for:	p5-Net-FTP-Common
# Date Created:				17 May, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FTP-Common
PORTVERSION=	5.32
CATEGORIES=	ftp perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to provide simplify common usages of Net::FTP

RUN_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

PERL_CONFIGURE=	yes

MAN3=		Net::FTP::Common.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 # inherited from security/p5-Authen-SASL
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
