# New ports collection makefile for:    xblast
# Date created:         Sat Nov 08 09:47:12 CET 1997
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	xblast-beta
PORTVERSION=	2.7.38
CATEGORIES=	games
MASTER_SITES=	http://www.ndh.net/home/m.vogel/tnt/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
DISTFILES=	xblast-2.6.1.sound${EXTRACT_SUFX} \
		image.tar.gz \
		level.tar.gz \
		xblast-tnt-unix.tar.gz

MAINTAINER=	se@FreeBSD.org

WRKSRC=		${WRKDIR}/XBlast-2.6-sound
USE_IMAKE=	yes
MAN1=		xblast.1

pre-fetch:
		@echo "There is no version number in xblast-tnt-unix.tar.gz"
		@echo "and this file is replaced by the program author without"
		@echo "announcement, as it is a work in progress."
		@echo
		@echo "Please inform the port maintainer <${MAINTAINER}>,"
		@echo "if you get MD5 checksum errors. You can try building"
		@echo "with NO_CHECKSUM=yes, since most changes to that file"
		@echo "will not prevent the compilation from succeeding ..."
		@echo

post-extract:
		${MV} ${WRKDIR}/XBlast-TNT/* ${WRKSRC}
		${MV} ${WRKDIR}/image/block/* ${WRKSRC}/image/block
		${MV} ${WRKDIR}/image/misc/* ${WRKSRC}/image/misc
		${MV} ${WRKSRC}/level ${WRKSRC}/level~
		${MV} ${WRKDIR}/level ${WRKSRC}

.include <bsd.port.mk>
