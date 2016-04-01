# Created by: Razi Khaja <razi@genet.sickkids.on.ca>
# $FreeBSD$

PORTNAME=	Bio-Das
PORTVERSION=	1.17
PORTREVISION=	3
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client-side library for Distributed Genome Annotation System

RUN_DEPENDS=	p5-HTML-Parser>=3:www/p5-HTML-Parser \
		p5-bioperl>=0:biology/p5-bioperl \
		p5-libwww>=5:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
