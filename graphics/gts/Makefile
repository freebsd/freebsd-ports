# Created by: ijliao
# $FreeBSD$

PORTNAME=	gts
PORTVERSION=	0.7.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	GNU Triangulated Surface Library

LICENSE=	LGPL20

CONFLICTS=	pcb-[0-9]*

USES=		pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NETPBM
OPTIONS_SUB=	yes

NETPBM_DESC=		Build with libnetpbm support
NETPBM_LIB_DEPENDS=	libnetpbm.so:${PORTSDIR}/graphics/netpbm

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-extract:
.if ! ${PORT_OPTIONS:MNETPBM}
	@${REINPLACE_CMD} -e 's|netpbm="true"|netpbm="false"|' \
		${WRKSRC}/configure
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-release \$$(LT_RELEASE)||g ; s|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|'

.include <bsd.port.mk>
