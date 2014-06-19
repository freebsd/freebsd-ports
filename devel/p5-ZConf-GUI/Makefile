# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf-GUI
PORTVERSION=	1.1.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	GUI backend chooser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ZConf>=6.1.0:${PORTSDIR}/net/p5-ZConf \
		p5-Error-Helper>=1.0.0:${PORTSDIR}/devel/p5-Error-Helper \
		p5-Module-List>=0.003:${PORTSDIR}/devel/p5-Module-List \
		${LOCALBASE}/bin/xhost:${PORTSDIR}/x11/xhost
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
