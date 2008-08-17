# New ports collection makefile for:	irssi-otr
# Date created:		2008-08-16
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	irssi-otr
PORTVERSION=	0.2
CATEGORIES=	irc
MASTER_SITES=	ftp://download.tuxfamily.org/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	irssiotr

MAINTAINER=	wahjava@gmail.com
COMMENT=	A plugin for irssi for Off-the-Record (OTR) messaging

BUILD_DEPENDS=	${LOCALBASE}/include/irssi/src/common.h:${PORTSDIR}/irc/irssi
LIB_DEPENDS=	otr.4:${PORTSDIR}/security/libotr
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20

.include <bsd.port.mk>
