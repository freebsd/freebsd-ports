# New ports collection makefile for:	Dzip
# Date created:				08 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dzip
PORTVERSION=	2.9
CATEGORIES=	archivers
MASTER_SITES=	http://speeddemosarchive.com/dzip/
DISTNAME=	dz${PORTVERSION:S/.//g}src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	File compression utility specializing in Quake demo compression

USE_ZIP=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}
MAKEFILE=	${WRKSRC}/Makefile.linux
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${FIND} -E ${WRKDIR} -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@${REINPLACE_CMD} -e 's/ifdef BIG_ENDIAN/if _BYTE_ORDER == _BIG_ENDIAN/' \
		-e 's/ifndef BIG_ENDIAN/if _BYTE_ORDER == _LITTLE_ENDIAN/' \
		${WRKSRC}/dzip.h ${WRKSRC}/conmain.c ${WRKSRC}/dzip.h
	@${REINPLACE_CMD} -e 's/) $$(OBJECTS/&:T/' ${WRKSRCK}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
