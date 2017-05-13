# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Directory-Scratch
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Easy-to-use self-cleaning scratch space

BUILD_DEPENDS=	p5-Path-Class>0:devel/p5-Path-Class \
		p5-File-Slurp>=9999.12:devel/p5-File-Slurp \
		p5-String-Random>0:devel/p5-String-Random
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
BROKEN=	checksu mismatch


.include <bsd.port.mk>
