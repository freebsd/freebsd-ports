# Created by: AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	ngspice_rework
PORTVERSION=	26
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ngspice-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Mixed-signal circuit simulator derived from Spice and Cider

LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	Fails to link: missing sbrk

GNU_CONFIGURE=	yes
USES=		gmake libtool readline

CONFIGURE_ARGS=	--with-readline=yes \
		--enable-xspice

OPTIONS_DEFINE=		DEBUG X11
OPTIONS_DEFAULT=	X11

X11_USE=		XORG=ice,sm,x11,xaw,xext,xmu,xt
X11_CONFIGURE_WITH=	x

DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
