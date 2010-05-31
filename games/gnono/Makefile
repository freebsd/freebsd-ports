# New ports collection makefile for:	gnono
# Date created:		18 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnono
PORTVERSION=	1.9.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Uno card game

USE_BZIP2=	yes
USE_GNOME=	gtk20 libgnomeui
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN6=	${PORTNAME}.6

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
	    	's|-DG.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
