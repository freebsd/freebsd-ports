# Created by: AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	ngspice_rework
PORTVERSION=	25
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ngspice-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Mixed-signal circuit simulator derived from Spice and Cider

LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake

DEBUG_CONFIGURE_ENABLE=	debug
CONFIGURE_ARGS+=	--enable-xspice --with-readline=yes

.include <bsd.port.mk>
