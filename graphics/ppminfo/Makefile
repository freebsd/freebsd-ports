# New ports collection makefile for:	ppminfo
# Date created:		7 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppminfo
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.vanheusden.com/ppminfo/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows details of a ppm file

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

PLIST_FILES=	bin/${PORTNAME}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} 's|min(|MIN(|;s|max(|MAX(|' ${WRKSRC}/pi.c
	@${REINPLACE_CMD} 's|-O2||;/^LDFLAGS=/s|=|+=|;\
		/^DEBUG=/d' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
