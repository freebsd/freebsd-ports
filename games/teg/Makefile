# New ports collection makefile for:	teg
# Date created:				31 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	teg
PORTVERSION=	0.11.2
PORTREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn-based strategy game for GNOME

USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-ggz

GCONF_SCHEMAS=	teg.schemas

post-patch:
	@${GREP} -lR " LIST_NEXT" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's| LIST_NEXT| TEG_LIST_NEXT|g'
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|pl||g' \
		${WRKSRC}/docs/gnome-help/Makefile.in

.include <bsd.port.mk>
