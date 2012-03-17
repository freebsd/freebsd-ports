# New ports collection makefile for:	p5-ZConf-Runner-GUI-GTK
# Date created:		2009-10-19
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Runner-GUI-GTK
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	The GTK GUI backend for ZConf::Runner

BUILD_DEPENDS=	p5-ZConf>=0:${PORTSDIR}/net/p5-ZConf \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-ZConf-Runner>=0:${PORTSDIR}/deskutils/p5-ZConf-Runner \
		p5-File-MimeInfo>=0:${PORTSDIR}/devel/p5-File-MimeInfo
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ZConf::Runner::GUI::GTK.3

.include <bsd.port.mk>
