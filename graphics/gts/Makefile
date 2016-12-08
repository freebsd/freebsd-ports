# Created by: ijliao
# $FreeBSD$

PORTNAME=	gts
PORTVERSION=	0.7.6
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	GNU Triangulated Surface Library

LICENSE=	LGPL20

CONFLICTS=	pcb-[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NETPBM
OPTIONS_SUB=	yes

NETPBM_DESC=		Build with libnetpbm support
NETPBM_LIB_DEPENDS=	libnetpbm.so:graphics/netpbm

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNETPBM}
	@${REINPLACE_CMD} -e 's|netpbm="true"|netpbm="false"|' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
