# New ports collection makefile for:	klavaro
# Date created:		26 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klavaro
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Touchtyping trainer

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=		${PORTNAME}.1

.include <bsd.port.mk>
