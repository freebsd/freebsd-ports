# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-ShareDir-PathClass
PORTVERSION=	1.112440
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	File::ShareDir returning Path::Class objects

BUILD_DEPENDS=	p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
