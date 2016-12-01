# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Find-Rule-Perl
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Common rules for searching for Perl things

BUILD_DEPENDS=	p5-CPAN-Meta>=2.150010:devel/p5-CPAN-Meta \
		p5-File-Find-Rule>=0.20:devel/p5-File-Find-Rule \
		p5-Params-Util>=0.38:devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
