# Ports collection makefile for:  wormux
# Date created:			  Thu Dec 16 18:46:55 EET 2004
# Whom:				  Anton Yudin <toha@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wormux
DISTVERSION=	0.7.9
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/wormux/

MAINTAINER=	toha@toha.org.ua
COMMENT=	Wormux game

LIB_DEPENDS=	xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer ttf gfx net

CONFIGURE_ARGS=	--with-datadir-name=${DATADIR} --program-prefix="" \
		--mandir=${MANPREFIX}/man

MAN6=	wormux.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
