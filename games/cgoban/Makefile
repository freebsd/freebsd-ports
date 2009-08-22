# New ports collection makefile for:   cgoban
# Date created:        28 October 1996
# Whom:                simonm@dcs.gla.ac.uk
#
# $FreeBSD$
#

PORTNAME=	cgoban
PORTVERSION=	1.9.14
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}1/${PORTNAME}1/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Internet Go Server client and game editor

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	x11 ice sm

MAN6=		cgoban.6
PLIST_FILES=	bin/cgoban

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gnugo|${LOCALBASE}/bin/gnugo|' ${WRKSRC}/src/cgoban.c
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cgoban ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man6/cgoban.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
