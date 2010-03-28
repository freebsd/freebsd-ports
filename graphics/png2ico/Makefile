# New ports collection makefile for:	png2ico
# Date created:				23 Sep 2002
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	png2ico
PORTVERSION=	2002.12.08
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.winterdrache.de/freeware/png2ico/data/
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S/./-/g}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Converts PNG files to Windows icon resource files

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

MAN1=		png2ico.1
PLIST_FILES=	bin/png2ico
PORTDOCS=	bmp.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/png2ico.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bmp.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
