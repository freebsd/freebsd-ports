# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	HOP-Lexer
PORTVERSION=	0.032
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OVID
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Higher Order Perl Lexer

BUILD_DEPENDS=	p5-HOP-Stream>=0.01:${PORTSDIR}/devel/p5-HOP-Stream
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	HOP::Lexer.3 \
	HOP::Lexer::Article.3

.include <bsd.port.mk>
