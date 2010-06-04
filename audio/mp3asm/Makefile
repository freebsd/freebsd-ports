# ex:ts=8
# New ports collection makefile for:	mp3asm
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp3asm
PORTVERSION=	0.1.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.1.3-1
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	MP3 frame level editor

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-0.1

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-extract:
	@${RM} ${WRKSRC}/config.cache

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|getprogname|_getprogname|g' ${WRKSRC}/src/mp3asm.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in Changelog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
