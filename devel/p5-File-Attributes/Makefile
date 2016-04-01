# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Attributes
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	File::Attributes - Manipulate file metadata

BUILD_DEPENDS=	p5-YAML>=0:textproc/p5-YAML \
		p5-Directory-Scratch>=0:devel/p5-Directory-Scratch \
		p5-Best>=0:devel/p5-Best \
		p5-YAML-Syck>0:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
