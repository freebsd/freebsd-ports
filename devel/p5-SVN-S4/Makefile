# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	SVN-S4
PORTVERSION=	1.062
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gary@hayers.org
COMMENT=	Wrapper for subversion program

LICENSE=	ART20 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Tiny>=0:devel/p5-Config-Tiny \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-IO-AIO>=0:devel/p5-IO-AIO \
		p5-subversion>=0:devel/p5-subversion
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

.include <bsd.port.mk>
