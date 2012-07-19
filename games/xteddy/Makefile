# New ports collection makefile for:   xteddy
# Date created:        3 June 1998
# Whom:                Eckart "Isegrim" Hofmann
#
# $FreeBSD$
#    $MCom: ports/games/xteddy/Makefile,v 1.1 2006/10/04 13:16:56 ahze Exp $

PORTNAME=	xteddy
PORTVERSION=	2.2
CATEGORIES=	games
MASTER_SITES=	http://webstaff.itn.liu.se/~stegu/xteddy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cuddlesome teddy for the X desktop

LICENSE=	GPLv2

USE_EFL=	imlib2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		xteddy.6
PLIST_FILES=	bin/xteddy bin/xteddy_test bin/xtoys \
		%%DATADIR%%/teddy.png %%DATADIR%%/xalex.png \
		%%DATADIR%%/xbobo.png %%DATADIR%%/xbrummi.png \
		%%DATADIR%%/xcherubino.png %%DATADIR%%/xduck.png \
		%%DATADIR%%/xhedgehog.png %%DATADIR%%/xklitze.png \
		%%DATADIR%%/xnamu.png %%DATADIR%%/xorca.png \
		%%DATADIR%%/xpenguin.png %%DATADIR%%/xpuppy.png \
		%%DATADIR%%/xruessel.png %%DATADIR%%/xteddy.png \
		%%DATADIR%%/xtrouble.png %%DATADIR%%/xtuxxy.png
PLIST_DIRS=	%%DATADIR%%

post-patch:
.for f in configure xteddy.c
	@${REINPLACE_CMD} -e \
		's|/usr/share/xteddy|${DATADIR}|' ${WRKSRC}/${f}
.endfor
.for f in xteddy_test xtoys
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
