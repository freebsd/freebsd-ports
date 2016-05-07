# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Attributes-Recursive
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Inherit file attributes from parent directories

BUILD_DEPENDS=	p5-Directory-Scratch>=0:devel/p5-Directory-Scratch \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-File-Attributes>=0:devel/p5-File-Attributes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
