PORTNAME=	amigadepacker
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://zakalwe.fi/~shd/foss/amigadepacker/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool for depacking some compressed Amiga formats
WWW=		https://zakalwe.fi/~shd/opensource.html

LICENSE=	GPLv2

USES=		tar:bzip2
HAS_CONFIGURE=	yes
USE_CSTD=	gnu89

CONFIGURE_ARGS+=	--prefix=${PREFIX}
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/amigadepacker share/man/man1/amigadepacker.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
