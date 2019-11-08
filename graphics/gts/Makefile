# Created by: ijliao
# $FreeBSD$

PORTNAME=	gts
PORTVERSION=	0.7.6
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	GNU Triangulated Surface Library

LICENSE=	LGPL20

CONFLICTS=	pcb-[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gnome libtool localbase pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NETPBM
OPTIONS_SUB=	yes

NETPBM_CONFIGURE_ENV_OFF=	ac_cv_lib_netpbm_pgm_init=no
NETPBM_LIB_DEPENDS=	libnetpbm.so:graphics/netpbm

post-patch-NETPBM-on:
	@${REINPLACE_CMD} -e 's|<pgm.h>|<netpbm/pgm.h>|' \
		${WRKSRC}/examples/happrox.c

.include <bsd.port.mk>
