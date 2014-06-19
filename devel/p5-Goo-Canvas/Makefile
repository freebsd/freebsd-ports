# Created by: Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Goo-Canvas
PORTVERSION=	0.06
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to the GooCanvas

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
LIB_DEPENDS=	goocanvas:${PORTSDIR}/graphics/goocanvas
RUN_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_GNOME=	gdkpixbuf
USE_PERL5=	configure build run
USES=		perl5

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
