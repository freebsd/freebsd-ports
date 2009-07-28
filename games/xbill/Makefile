# ex:ts=8
# Ports collection makefile for:  xbill
# Date created:			  12 September 1995
# Whom:				  asami
#
# $FreeBSD$
#

PORTNAME=	xbill
PORTVERSION=	2.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.xbill.org/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Save your computers from the evil clutches of Bill

GNU_CONFIGURE=	yes
WANT_GNOME=	yes
CONFIGURE_ARGS=	--localstatedir=${SCORES_DIR}

MAN6=		xbill.6

SCORES_DIR?=	${DATADIR}/scores

OPTIONS=	ATHENA	"Build with Athena widget set" off \
		GTK	"Build with GTK widget set" on \
		MOTIF	"Build with Motif widget set" off

.include <bsd.port.pre.mk>

.if defined(WITH_ATHENA) && !defined(WITH_GTK) && !defined(WITH_MOTIF)
CONFIGURE_ARGS+=	--disable-gtk --disable-motif
USE_XORG=	xaw xmu xt x11 sm ice
.elif !defined(WITH_ATHENA) && defined(WITH_GTK) && !defined(WITH_MOTIF)
CONFIGURE_ARGS+=	--disable-athena --disable-motif
USE_GNOME=	gtk12
USE_XORG=	sm ice
.elif !defined(WITH_ATHENA) && !defined(WITH_GTK) && defined(WITH_MOTIF)
CONFIGURE_ARGS+=	--disable-athena --disable-gtk
USE_XORG=	xt x11 sm ice xpm
USE_MOTIF=	yes
.else
IGNORE=		can't be build: please rerun 'make config' and chose exactly one widget set
.endif

post-patch:
	@${REINPLACE_CMD} -e '/WIDGET_LIBS=/ s|-lXm"$$|-lXm -lXpm"|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
