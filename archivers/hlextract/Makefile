# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hlextract
PORTVERSION=	2.4.4
CATEGORIES=	archivers games
MASTER_SITES=	http://nemesis.thewavelength.net/files/files/
DISTNAME=	hllib${PORTVERSION:S/.//g}

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Utility to extract data from various Half-Life file formats

LICENSE=	GPLv2

LIB_DEPENDS=	hl:${PORTSDIR}/games/hllib

NO_STAGE=	yes
USE_DOS2UNIX=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/HLExtract

PATCH_WRKSRC=	${WRKDIR}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
		${WRKSRC}/Main.c -o ${WRKSRC}/${PORTNAME} -lhl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
