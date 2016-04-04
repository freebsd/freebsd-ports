# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Recent-Uploads
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Find the distributions recently uploaded to CPAN

RUN_DEPENDS=	p5-libwww>=5.835:www/p5-libwww \
		p5-URI>=1.56:net/p5-URI \
		p5-YAML-Syck>=1.15:textproc/p5-YAML-Syck
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
