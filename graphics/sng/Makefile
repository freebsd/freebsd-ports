# ex:ts=8
# New ports collection makefile for:	sng
# Date created:			Mar 20, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sng
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	compiler/decompiler for Scriptable Network Graphics

BUILD_DEPENDS=	${X11BASE}/lib/X11/rgb.txt:${X_CLIENTS_PORT}
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-png-inc=${LOCALBASE}/include \
		--with-rgbtxt=${X11BASE}/lib/X11/rgb.txt
USE_GMAKE=	yes

MAN1=	sng.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-static||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
