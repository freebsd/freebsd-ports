# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	Baseball-Sabermetrics
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Baseball Statistics Module

BUILD_DEPENDS=	p5-Data-Serializer>=0.29:devel/p5-Data-Serializer \
		p5-HTML-TableExtract>=2.08:www/p5-HTML-TableExtract \
		p5-libwww>=5.801:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
