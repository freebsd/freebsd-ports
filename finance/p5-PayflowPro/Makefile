# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	PayflowPro
PORTVERSION=	3101
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VKHERA
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Pure Perl PayflowPro payment gateway interface

RUN_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/ca-bundle.crt ${LOCALBASE}/etc

MAN3=		PayflowPro.3
PLIST_FILES=	etc/ca-bundle.crt \
		%%SITE_PERL%%/PayflowPro.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/PayflowPro/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/PayflowPro

.include <bsd.port.mk>
