PORTNAME=	pngphoon
DISTVERSION=	1.4
CATEGORIES=	astro
MASTER_SITES=	https://svolli.de/software/pngphoon/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	PNG Phase of Moon
WWW=		https://svolli.de/software/pngphoon/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng16.so:graphics/png

USES=		gmake localbase:ldflags shebangfix tar:bz2
SHEBANG_FILES=	contrib/phoonX

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/pngphoon bin/phoonX share/man/man1/pngphoon.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngphoon ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/phoonX ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/contrib/pngphoon.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
