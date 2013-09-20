# Created by: AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	ngspice_rework
PORTVERSION=	25
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ngspice-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Mixed-signal circuit simulator derived from Spice and Cider

OPTIONS_DEFINE=	DEBUG

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--enable-xspice \
		--with-readline=yes

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

MAN1=		ngspice.1 ngnutmeg.1 ngsconvert.1 ngmultidec.1

.include <bsd.port.mk>
