# New ports collection makefile for:	gtktetcolor
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtktetcolor
PORTVERSION=	0.6.4
PORTREVISION=	10
CATEGORIES=	games gnome
MASTER_SITES=	SUNSITE/games \
		http://canopus.iacp.dvo.ru/~panov/gtktetcolor/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game for GNOME that resembles well-known tetris and columns

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|games\.games|games:games|g' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
