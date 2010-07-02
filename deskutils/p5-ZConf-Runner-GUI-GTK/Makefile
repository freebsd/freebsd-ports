# New ports collection makefile for:	p5-ZConf-Runner-GUI-GTK
# Date created:		2009-10-19
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Runner-GUI-GTK
PORTVERSION=	0.0.2
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	The GTK GUI backend for ZConf::Runner

RUN_DEPENDS=	${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2

PERL_CONFIGURE=	yes

MAN3=		ZConf::Runner::GUI::GTK.3

.include <bsd.port.mk>
