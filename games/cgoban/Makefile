# New ports collection makefile for:   cgoban
# Date created:        28 October 1996
# Whom:                simonm@dcs.gla.ac.uk
#
# $FreeBSD$
#

PORTNAME=	cgoban
PORTVERSION=	1.9.14
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cgoban1

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Internet Go Server client and game editor

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN6=		cgoban.6
PLIST_FILES=	bin/cgoban

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gnugo|${LOCALBASE}/bin/gnugo|' ${WRKSRC}/src/cgoban.c
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cgoban ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man6/cgoban.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
