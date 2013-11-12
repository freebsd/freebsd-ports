# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xabacus
PORTVERSION=	7.7.1
CATEGORIES=	games
MASTER_SITES=	http://www.tux.org/~bagleyd/abacus/ \
		http://ftp.tux.org/pub/tux/bagleyd/xabacus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abacus for X Window System

LICENSE=	BSD

OPTIONS_DEFINE=	MOTIF ESOUND
OPTIONS_DEFAULT=	MOTIF

USE_BZIP2=	yes
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-nas

MOTIF_USES=	motif
MOTIF_CONFIGURE_WITH=	motif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--without-rplay --with-esound
.else
LIB_DEPENDS+=		librplay.so:${PORTSDIR}/audio/rplay
CONFIGURE_ARGS+=	--with-rplay --without-esound
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/games/|/|g' ${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e '/^XWIDGETLDFLAGS/d' ${WRKSRC}/Makefile

.include <bsd.port.mk>
