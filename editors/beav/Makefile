# New ports collection makefile for:	beav
# Date created:		01 July 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beav
PORTVERSION=	1.40.15
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/b/beav/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Binary Editor And Viewer, a full featured binary file editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_REINPLACE=	yes
ALL_TARGET=	beav

MAN1=		beav.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=-DUNIX -DBSD #|g ; \
		 s|^CC=|CC?=|g ; \
		 s|^(|\$$(|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/doc/beav|${DOCSDIR}|g' ${WRKSRC}/beav.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beav ${PREFIX}/bin/beav
	${INSTALL_MAN} ${WRKSRC}/beav.1 ${MANPREFIX}/man/man1/beav.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/beav140.txt ${DOCSDIR}/beav.txt
.endif

.include <bsd.port.mk>
