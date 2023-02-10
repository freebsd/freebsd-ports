PORTNAME=	id3ed
PORTVERSION=	1.10.4
CATEGORIES=	audio
MASTER_SITES=	http://code.fluffytapeworm.com/projects/${PORTNAME}/

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	Id3 tag editor for mp3 files
WWW=		http://code.fluffytapeworm.com/projects/id3ed

LICENSE=	GPLv2

DEPRECATED=	Abandonware and obsolete, doesn't support ID3v2 tagging
EXPIRATION_DATE=2023-03-31

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/id3ed \
		man/man1/id3ed.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3ed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/id3ed.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
