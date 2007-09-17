# New ports collection makefile for:	asunder
# Date created:				14 September 2007
# Whom:					frase@frase.id.au
#
# $FreeBSD$

PORTNAME=	asunder
PORTVERSION=	0.8.1
CATEGORIES=	audio
MASTER_SITES=	http://littlesvr.ca/asunder/releases/

MAINTAINER=	frase@frase.id.au
COMMENT=	A lightweight GTK+ CD ripper

LIB_DEPENDS=	cddb.4:${PORTSDIR}/audio/libcddb
RUN_DEPENDS=	${LOCALBASE}/bin/cdparanoia:${PORTSDIR}/audio/cdparanoia

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GNOME=	gtk20

.include <bsd.port.mk>
