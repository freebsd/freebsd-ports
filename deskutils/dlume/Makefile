# New ports collection makefile for:	dlume
# Date created:				07 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dlume
PORTVERSION=	0.1.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://clay.ll.pl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 address book

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		${PORTNAME}.1

.include <bsd.port.mk>
