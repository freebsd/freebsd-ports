# Created by: simonm@dcs.gla.ac.uk
# $FreeBSD$

PORTNAME=	cgoban
PORTVERSION=	1.9.14
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}1/${PORTNAME}1/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Internet Go Server client and game editor

GNU_CONFIGURE=	yes
USE_XORG=	x11 ice sm

PLIST_FILES=	bin/cgoban \
		man/man6/cgoban.6.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gnugo|${LOCALBASE}/bin/gnugo|' ${WRKSRC}/src/cgoban.c
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|; \
		/CFLAGS='\''-O2/ d' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cgoban ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man6/cgoban.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

.include <bsd.port.mk>
