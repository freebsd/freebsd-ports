# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-API-Peek
DISTVERSION=	2.20
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Peek into the internals of a running POE environment

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-POE>=1.311:devel/p5-POE \
		p5-Devel-Size>0:devel/p5-Devel-Size
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

regression-test:
	@(cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} && ${MAKE} test)

.include <bsd.port.mk>
