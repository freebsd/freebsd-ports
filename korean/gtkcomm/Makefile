# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	gtkcomm
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	korean comms
MASTER_SITES=	http://kldp.net/frs/download.php/480/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Serial controlling software, with gtk+ widget

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/fonts/baekmukfonts/gulim12.pcf.gz:korean/baekmukfonts-bdf

USES=		gettext pathfix perl5 pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.in Makefile.in.in
USE_PERL5=	build
USE_GNOME=	glib20 gtk20
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

.include <bsd.port.mk>
