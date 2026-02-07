PORTNAME=	ppunpack
PORTVERSION=	1.0
CATEGORIES=	archivers
MASTER_SITES=	LOCAL/thierry
DISTNAME=	ppsmall-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decompresses Amiga PowerPacker files

# Converted from NO_CDROM
LICENSE=	PPUNPACK
LICENSE_NAME=	PPUnpack
LICENSE_TEXT=	No commercial redistribution
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		tar:Z
WRKSRC=		${WRKDIR}/PPUnpack
MAKE_ARGS=	CC="${CC}" COPTS="${CFLAGS}"
PLIST_FILES=	bin/ppunpack
ALL_TARGET=	ppunpack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
