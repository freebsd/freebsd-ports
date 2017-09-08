# Created by: ijliao
# $FreeBSD$

PORTNAME=	mp3asm
PORTVERSION=	0.1.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}-${PORTVERSION:E}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MP3 frame level editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2

PLIST_FILES=	bin/mp3asm
PORTDOCS=	Changelog README
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:R}

post-patch:
	@${RM} ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e '/^CFLAGS=/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|getprogname|mp3info_&|' ${WRKSRC}/src/mp3asm.c
	@${REINPLACE_CMD} -e '/^#include <argz.h>/d' ${WRKSRC}/src/mp3asm.h
	@${REINPLACE_CMD} -e 's|\([ (!]\)\(log[\.;]\)|\1mp3asm_\2|g' ${WRKSRC}/src/*.c ${WRKSRC}/src/mp3asm.h

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
