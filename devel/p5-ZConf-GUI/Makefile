# New ports collection makefile for:	devel/p5-ZConf-GUI
# Date created:		2009-05-25
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-GUI
PORTVERSION=	1.0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A GUI backend chooser

RUN_DEPENDS=	p5-ZConf>=6.1.0:${PORTSDIR}/net/p5-ZConf \
		${LOCALBASE}/bin/xhost:${PORTSDIR}/x11/xhost

PERL_CONFIGURE=	yes

MAN3=		ZConf::GUI.3

.include <bsd.port.mk>
