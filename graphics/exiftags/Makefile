# ex:ts=8
# Ports collection makefile for:	exiftags
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	exiftags
PORTVERSION=	0.93
CATEGORIES=	graphics
MASTER_SITES=	http://johnst.org/sw/exiftags/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes

MAN1=	exiftags.1

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g" -e "s,^CFLAGS,#CFLAGS,g" \
		-e "s,^PREFIX,#PREFIX,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exiftags ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/exiftags.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
