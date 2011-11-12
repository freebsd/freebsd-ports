# New ports collection makefile for:	dcraw
# Date created: 			14 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	dcraw
PORTVERSION=	9.11
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Decoder for RAW files from digital cameras

LIB_DEPENDS=	jasper:${PORTSDIR}/graphics/jasper \
		jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/jasper
LDFLAGS+=	-L${LOCALBASE}/lib -lm -ljasper -ljpeg -llcms

MAN1=		dcraw.1
PLIST_FILES=	bin/dcraw

do-build:
	cd ${WRKSRC}/ && ${CC} -o dcraw ${CFLAGS} dcraw.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/

make-dist:
	@${RM} -rf ${WRKDIR};${MKDIR} ${WRKDIR};cd ${WRKDIR};\
	${FETCH_CMD} http://cybercom.net/~dcoffin/dcraw/dcraw.c;\
	${FETCH_CMD} http://cybercom.net/~dcoffin/dcraw/dcraw.1;\
	ver=`grep -o -m1 -E '[2-9]\.[0-9][0-9]' dcraw.c`;\
	${MKDIR} dcraw-$$ver;mv dcraw.[c1] dcraw-$$ver;\
	${TAR} cjvf dcraw-$$ver.tar.bz2 dcraw-$$ver

.include <bsd.port.mk>
