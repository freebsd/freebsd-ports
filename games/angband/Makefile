# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	angband
PORTVERSION=	3.4.1
CATEGORIES=	games
MASTER_SITES=	http://rephial.org/downloads/${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rogue-like game with color, X11 support

USE_GMAKE=	yes
ALL_TARGET=	#
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-setgid=games --localstatedir=/var
LDFLAGS+=	-lncursesw

OPTIONS_DEFINE=	X11
X11_DESC=	Enable X11 (graphical) backend

OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	sm x11
RUN_DEPENDS=	xorg-fonts-miscbitmaps>=0:${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps
.else
CONFIGURE_ARGS+=--disable-x11
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers ||; s|/games$$|/bin|' ${WRKSRC}/configure

.include <bsd.port.mk>
