# Created by: ijliao
# $FreeBSD$

PORTNAME=	Finance-TW-TSEQuote
PORTVERSION=	0.28
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Check stock quotes from Taiwan Security Exchange

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Cache>=0:devel/p5-App-Cache \
		p5-HTML-TableExtract>=0:www/p5-HTML-TableExtract \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-URI>=0:net/p5-URI \
		p5-YAML>=0:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
