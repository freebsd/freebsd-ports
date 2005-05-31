# ex:ts=8
# Ports collection makefile for:	crossword
# Date created:			Aug 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	crossword
PORTVERSION=	0.8.3
CATEGORIES=	games
MASTER_SITES=	http://www.ldc.usb.ve/~96-28234/

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Crossword Generator

WRKSRC=		${WRKDIR}/Crossword
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS|#CFLAGS|g" ${WRKSRC}/Makefile

do-install:
.for file in crossword crossword_heur crw2tex
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
