# New ports collection makefile for:    kbanner
# Version required:	2.1
# Date created:		Fri Feb 26 15:07:10 PST 1999
# Whom:			sumikawa
#
# $FreeBSD$
#

DISTNAME=	kbanner-2.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/NetNews/fj.sources/volume93/Oct/
DISTFILES=	931016.04.Z 931016.05.Z 931016.06.Z \
		931016.07.Z 931016.08.Z 931016.09.Z

MAINTAINER=	sumikawa@kame.net

DIST_SUBDIR=	kbanner
WRKSRC=		$(WRKDIR)/kbanner2.1
ALL_TARGET=	kbanner
MAN1=		kbanner.1

TMPFILE=	kbanner.uu.txt
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	-cd
EXTRACT_AFTER_ARGS=	>> ${TMPFILE}

post-extract:
	cd ${WRKDIR} && ${SED} '/^END/,/^BEGIN/d' ${TMPFILE} | uudecode -p | tar zxvf -

.include <bsd.port.mk>
