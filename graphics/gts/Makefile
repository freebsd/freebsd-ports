# Created by: ijliao
# $FreeBSD$

PORTNAME=	gts
PORTVERSION=	0.7.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	GNU Triangulated Surface Library

USE_GNOME=	glib20 pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NETPBM
NETPBM_DESC=	Build with libnetpbm support

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNETPBM}
LIB_DEPENDS+=	netpbm.1:${PORTSDIR}/graphics/netpbm
PLIST_SUB=	NETPBM=""
.else
PLIST_SUB=	NETPBM="@comment "
.endif

post-extract:
.if ! ${PORT_OPTIONS:MNETPBM}
	@${REINPLACE_CMD} -e 's|netpbm="true"|netpbm="false"|' \
		${WRKSRC}/configure
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-release \$$(LT_RELEASE)||g ; s|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|'

.include <bsd.port.mk>
