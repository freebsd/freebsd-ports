# ports collection makefile for:	qrq
# Date created:				1 July 2007
# Whom:					db
#
# $FreeBSD$
#

PORTNAME=	qrq
PORTVERSION=	0.1.0
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/qrq/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Morse telegraphy trainer similar to the classic DOS version by DL4MM

MAN1=		qrq.1

LDFLAGS+=	-lm -lncurses -lpthread
CFLAGS+=	-DDESTDIR=\"${PREFIX}\" -DVERSION=\"${PORTVERSION}\"

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	${MKDIR} ${DATADIR}
.for f in callbase qrqrc toplist
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.include <bsd.port.mk>
