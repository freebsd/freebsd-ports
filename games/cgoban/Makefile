PORTNAME=	cgoban
PORTVERSION=	1.9.14
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}1/${PORTNAME}1/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Internet Go Server client and game editor
WWW=		https://cgoban1.sourceforge.net/

GNU_CONFIGURE=	yes
USES=		xorg
USE_XORG=	x11 ice sm

PLIST_FILES=	bin/cgoban \
		share/man/man6/cgoban.6.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gnugo|${LOCALBASE}/bin/gnugo|' ${WRKSRC}/src/cgoban.c
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|; \
		/CFLAGS='\''-O2/ d' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cgoban ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man6/cgoban.6 ${STAGEDIR}${PREFIX}/share/man/man6/

.include <bsd.port.mk>
