# Created by: Patrick Seal <patseal@hyperhost.net>

PORTNAME=	mscompress
PORTVERSION=	0.3
CATEGORIES=	archivers
MASTER_SITES=	SUNSITE/utils/compress

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Microsoft "compress.exe/expand.exe" compatible (de)compressor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
HAS_CONFIGURE=	yes

CONFLICTS_INSTALL=	foo2zjs # bin/msexpand

PLIST_FILES=	bin/mscompress bin/msexpand \
		share/man/man1/mscompress.1.gz \
		share/man/man1/msexpand.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mscompress ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/msexpand ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mscompress.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/msexpand.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
