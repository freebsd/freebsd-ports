# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	png2ico
PORTVERSION=	2002.12.08
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.winterdrache.de/freeware/png2ico/data/
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts PNG files to Windows icon resource files

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

MAN1=		png2ico.1
PLIST_FILES=	bin/png2ico
PORTDOCS=	bmp.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
