# New ports collection makefile for:	xmms-cdread
# Date created:				12 May 2003
# Whom:					Sergey V. Belov <argail@csite.ru>
#
# $FreeBSD$
#

PORTNAME=	xmms-cdread
PORTVERSION=	0.14a
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/willem/

MAINTAINER=	argail@visit.ru
COMMENT=	A XMMS input plugin for read AudioCD via IDE bus

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
