# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf-GUI
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	GUI backend chooser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ZConf>=6.1.0:net/p5-ZConf \
		p5-Error-Helper>=1.0.0:devel/p5-Error-Helper \
		p5-Module-List>=0.003:devel/p5-Module-List \
		${LOCALBASE}/bin/xhost:x11/xhost
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	bin/*

.include <bsd.port.mk>
