# New ports collection makefile for:	klavaro
# Date created:		26 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klavaro
PORTVERSION=	1.9.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Touchtyping trainer

LICENSE=	GPLv3

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtkdatabox-0.9.1.3:${PORTSDIR}/x11-toolkits/gtkdatabox

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/gtkdatabox
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1

post-extract:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/data/klavaro.desktop.in

.include <bsd.port.mk>
