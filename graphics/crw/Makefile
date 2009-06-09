# New ports collection makefile for:    crw
# Date created:         16 June 2002
# Whom:                 dillon
#
# $FreeBSD$
#

PORTNAME=	crw
PORTVERSION=	1.03
CATEGORIES=	graphics
MASTER_SITES=	http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility to process Canon camera RAW (.crw) files

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

MAN1=		crw.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/crw

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/lib,${LOCALBASE}/lib,' \
			-e 's,/usr/local/include,${LOCALBASE}/include,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
