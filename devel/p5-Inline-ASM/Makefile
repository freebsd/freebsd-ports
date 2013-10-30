# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Inline-ASM
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl Subroutines in assembler

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	</dev/null

.include <bsd.port.mk>
