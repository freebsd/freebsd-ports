# New ports collection makefile for:	gtktetcolor
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtktetcolor
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.dvgu.ru/ifit/~panov/gtktetcolor/
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game for GNOME that resembles well-known tetris and columns

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		's|games\.games|games:games|g' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
