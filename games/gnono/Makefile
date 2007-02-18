# New ports collection makefile for:	gnono
# Date created:		18 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnono
PORTVERSION=	1.9.1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Uno card game

USE_BZIP2=	yes
USE_GNOME=	gtk20 libgnomeui
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN6=	${PORTNAME}.6

.include <bsd.port.mk>
