# New ports collection makefile for:	HLExtract
# Date created:				22 Oct 2007
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hlextract
PORTVERSION=	2.4.2
CATEGORIES=	archivers games
MASTER_SITES=	http://nemesis.thewavelength.net/files/files/
DISTNAME=	hllib${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to extract data from various Half-Life file formats

LICENSE=	GPLv2

LIB_DEPENDS=	hl:${PORTSDIR}/games/hllib

USE_ZIP=	yes
USE_DOS2UNIX=	Main.c
WRKSRC=		${WRKDIR}/HLExtract

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,linux/limits,sys/param, ; \
		s,HLExtract\.exe,${PORTNAME},' ${WRKSRC}/Main.c

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
		${WRKSRC}/Main.c -o ${WRKSRC}/${PORTNAME} -lhl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
