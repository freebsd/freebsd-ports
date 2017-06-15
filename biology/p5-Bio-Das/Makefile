# Created by: Razi Khaja <razi@genet.sickkids.on.ca>
# $FreeBSD$

PORTNAME=	Bio-Das
PORTVERSION=	1.17
PORTREVISION=	4
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client-side library for Distributed Genome Annotation System

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-BioPerl>=0:biology/p5-BioPerl \
		p5-HTML-Parser>=3:www/p5-HTML-Parser \
		p5-libwww>=5:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
