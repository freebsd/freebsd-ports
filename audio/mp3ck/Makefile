PORTNAME=	mp3ck
PORTVERSION=	0.04
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Consistency check utility for MPEG Layer 2 or 3 files or streams
WWW=		https://mp3ck.sourceforge.net/

DEPRECATED=	Last release in 2005 and dead upstream, consider using multimedia/ffmpeg
EXPIRATION_DATE=2024-02-29

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

PLIST_FILES=	bin/mp3ck man/man1/mp3ck.1.gz

.include <bsd.port.mk>
