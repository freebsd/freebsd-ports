# New ports collection makefile for:	klavaro
# Date created:		26 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klavaro
PORTVERSION=	1.7.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Touchtyping trainer

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtkdatabox-0.9.0.1:${PORTSDIR}/x11-toolkits/gtkdatabox

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/gtkdatabox
LDFLAGS=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		${PORTNAME}.1

.include <bsd.port.mk>
