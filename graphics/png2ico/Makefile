# New ports collection makefile for:	png2ico
# Date created:				23 Sep 2002
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	png2ico
PORTVERSION=	2002.12.08
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.winterdrache.de/freeware/png2ico/data/
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S/./-/g}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Converts PNG files to Windows icon resource files

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

MAN1=		png2ico.1

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/png2ico.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
