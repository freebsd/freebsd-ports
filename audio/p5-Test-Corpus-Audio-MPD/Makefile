# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Corpus-Audio-MPD
PORTVERSION=	1.120990
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automate launching of fake mdp for testing purposes

BUILD_DEPENDS=	p5-File-ShareDir-PathClass>0:devel/p5-File-ShareDir-PathClass \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Readonly>=0:devel/p5-Readonly
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
