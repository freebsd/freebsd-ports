# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forks
PORTVERSION=	0.36
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/SOAP/RYBSKEJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Drop-in replacement for Perl threads using fork()

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Acme-Damn>=0:devel/p5-Acme-Damn \
		p5-Attribute-Handlers>=0:devel/p5-Attribute-Handlers \
		p5-Devel-Symdump>=0:devel/p5-Devel-Symdump \
		p5-List-MoreUtils>=:lang/p5-List-MoreUtils \
		p5-Sys-SigAction>=0.11:devel/p5-Sys-SigAction
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	</dev/null

.include <bsd.port.mk>
