# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	gtkcomm
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	korean comms
MASTER_SITES=	http://kldp.net/frs/download.php/480/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Serial controlling software, with gtk+ widget

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USES=		perl5 pkgconfig
USE_PERL5=	build
USE_GNOME=	glib20 gtk20
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

.include <bsd.port.mk>
