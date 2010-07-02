# New ports collection makefile for:	devel/p5-ZConf-GUI
# Date created:		2009-05-25
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-GUI
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A GUI backend chooser

RUN_DEPENDS=	${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		${LOCALBASE}/bin/xhost:${PORTSDIR}/x11/xhost

PERL_CONFIGURE=	yes

MAN3=		ZConf::GUI.3

.include <bsd.port.mk>
