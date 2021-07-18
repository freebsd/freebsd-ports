# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>

PORTNAME=	Goo-Canvas
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLMAX
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	2
DISTNAME=	GooCanvas2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl binding for GooCanvas2

LICENSE=	GPLv2

LIB_DEPENDS=	libgoocanvas-2.0.so:graphics/goocanvas2
RUN_DEPENDS=	p5-Glib>=1.210:devel/p5-Glib \
		p5-Gtk3>=0.026:x11-toolkits/p5-Gtk3

USES=		gnome perl5
USE_PERL5=	configure
USE_GNOME=	gtk30

.include <bsd.port.mk>
