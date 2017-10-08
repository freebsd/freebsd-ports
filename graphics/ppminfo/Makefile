# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ppminfo
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.vanheusden.com/ppminfo/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows details of a ppm file

LIB_DEPENDS=	libnetpbm.so:graphics/netpbm

USES=		localbase:ldflags ncurses tar:tgz
PLIST_FILES=	bin/${PORTNAME}
CFLAGS+=	-I${LOCALBASE}/include/netpbm

post-patch:
	@${REINPLACE_CMD} 's|min(|MIN(|;s|max(|MAX(|' ${WRKSRC}/pi.c
	@${REINPLACE_CMD} 's|-O2||;/^LDFLAGS=/s|=|+=|;\
		/^DEBUG=/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
