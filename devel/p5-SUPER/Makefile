# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	SUPER
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl module control superclass method dispatch

BUILD_DEPENDS=	p5-Sub-Identify>=0.04:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-Scalar-List-Utils>=0.20:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	SUPER.3

.include <bsd.port.mk>
