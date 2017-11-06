# Created by: AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	ngspice_rework
PORTVERSION=	26
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ngspice-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Mixed-signal circuit simulator derived from Spice and Cider

LICENSE=	BSD3CLAUSE BSD4CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		gmake libtool readline
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-cider --enable-xspice --with-readline=yes

OPTIONS_DEFINE=			DEBUG
OPTIONS_DEFAULT=		X11
OPTIONS_SINGLE=			INTERFACE
OPTIONS_SINGLE_INTERFACE=	SHLIB X11
OPTIONS_SUB=			yes

SHLIB_DESC=		Build as a shared library

DEBUG_CONFIGURE_ENABLE=	debug

SHLIB_CONFIGURE_WITH=	ngshared

X11_USE=		XORG=ice,sm,x11,xaw,xext,xmu,xt
X11_CONFIGURE_WITH=	x

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
