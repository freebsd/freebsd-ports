# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amigadepacker
PORTVERSION=	0.04
CATEGORIES=	archivers
MASTER_SITES=	http://zakalwe.fi/~shd/foss/amigadepacker/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool for depacking some compressed Amiga formats

LICENSE=	GPLv2

USES=		tar:bzip2
HAS_CONFIGURE=	yes
USE_CSTD=	gnu89

CONFIGURE_ARGS+=	--prefix=${PREFIX}
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/amigadepacker man/man1/amigadepacker.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
