# New ports collection makefile for:	p5-PayflowPro
# Date created:				Wed Oct 24 10:09:12 EDT 2007
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	PayflowPro
PORTVERSION=	2111
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/V/VK/VKHERA
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Pure Perl PayflowPro payment gateway interface

RUN_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/ca-bundle.crt ${LOCALBASE}/etc

MAN3=		PayflowPro.3
PLIST_FILES=	etc/ca-bundle.crt \
		%%SITE_PERL%%/PayflowPro.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/PayflowPro/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/PayflowPro

.include <bsd.port.mk>
