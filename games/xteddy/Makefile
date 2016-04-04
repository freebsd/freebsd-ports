# Created by: Eckart "Isegrim" Hofmann
# $FreeBSD$

PORTNAME=	xteddy
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://webstaff.itn.liu.se/~stegu/xteddy/ \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Cuddlesome teddy for the X desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		localbase pkgconfig
GNU_CONFIGURE=	yes

LDFLAGS+=	-lXext

PLIST_FILES=	bin/xteddy bin/xteddy_test bin/xtoys \
		man/man6/xteddy.6.gz \
		%%DATADIR%%/teddy.png %%DATADIR%%/xalex.png \
		%%DATADIR%%/xbobo.png %%DATADIR%%/xbrummi.png \
		%%DATADIR%%/xcherubino.png %%DATADIR%%/xduck.png \
		%%DATADIR%%/xhedgehog.png %%DATADIR%%/xklitze.png \
		%%DATADIR%%/xnamu.png %%DATADIR%%/xorca.png \
		%%DATADIR%%/xpenguin.png %%DATADIR%%/xpuppy.png \
		%%DATADIR%%/xruessel.png %%DATADIR%%/xteddy.png \
		%%DATADIR%%/xtrouble.png %%DATADIR%%/xtuxxy.png

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
