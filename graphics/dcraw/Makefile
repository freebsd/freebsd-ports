# New ports collection makefile for:	dcraw
# Date created: 			14 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	dcraw
PORTVERSION=	9.05
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decoder for RAW files from digital cameras

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms

USE_BZIP2=	yes

MAN1=		dcraw.1
PLIST_FILES=	bin/dcraw

do-build:
	cd "${BUILD_WRKSRC}/" && ${CC} -o dcraw ${CFLAGS} -I"${PREFIX}"/include \
		dcraw.c -L"${PREFIX}"/lib -lm -ljpeg -llcms

do-install:
	${INSTALL_PROGRAM} "${WRKSRC}"/${PORTNAME} "${PREFIX}"/bin/
	${INSTALL_MAN} "${WRKSRC}"/${MAN1} "${PREFIX}"/man/man1/

make-dist:
	@${RM} -rf ${WRKDIR};${MKDIR} ${WRKDIR};cd ${WRKDIR};\
	${FETCH_CMD} http://cybercom.net/~dcoffin/dcraw/dcraw.c;\
	${FETCH_CMD} http://cybercom.net/~dcoffin/dcraw/dcraw.1;\
	ver=`grep -o -m1 -E '[2-9]\.[0-9][0-9]' dcraw.c`;\
	${MKDIR} dcraw-$$ver;mv dcraw.[c1] dcraw-$$ver;\
	${TAR} cjvf dcraw-$$ver.tar.bz2 dcraw-$$ver

.include <bsd.port.mk>
