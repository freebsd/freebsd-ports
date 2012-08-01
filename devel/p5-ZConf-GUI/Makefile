# New ports collection makefile for:	devel/p5-ZConf-GUI
# Date created:		2009-05-25
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-GUI
PORTVERSION=	1.1.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A GUI backend chooser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ZConf>=6.1.0:${PORTSDIR}/net/p5-ZConf \
		p5-Error-Helper>=1.0.0:${PORTSDIR}/devel/p5-Error-Helper \
		p5-Module-List>=0.003:${PORTSDIR}/devel/p5-Module-List \
		${LOCALBASE}/bin/xhost:${PORTSDIR}/x11/xhost
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ZConf::GUI.3

.include <bsd.port.mk>
