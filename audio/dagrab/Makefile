PORTNAME=	dagrab
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/cdrom

MAINTAINER=	clkao@CirX.ORG
COMMENT=	Read audio tracks from a CD into wav sound files

PLIST_FILES=	bin/dagrab \
		man/man1/dagrab.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dagrab ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dagrab.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
