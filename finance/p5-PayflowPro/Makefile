# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	PayflowPro
PORTVERSION=	4706
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VKHERA
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Pure Perl PayflowPro payment gateway interface

RUN_DEPENDS+=	p5-libwww>0.0:www/p5-libwww
BUILD_DEPENDS+=	p5-libwww>0.0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/ca-bundle.crt ${STAGEDIR}${PREFIX}/etc

PLIST_FILES=	etc/ca-bundle.crt \
		%%SITE_PERL%%/PayflowPro.pm \
		%%SITE_PERL%%/mk-ca-bundle.pl \
		%%PERL5_MAN3%%/PayflowPro.3.gz

.include <bsd.port.mk>
