# New ports collection makefile for:    kbanner
# Date created:		Fri Feb 26 15:07:10 PST 1999
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	kbanner
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/news/fj.sources/V24/
DISTFILES=	2426.gz 2427.gz 2428.gz 2429.gz 2430.gz 2431.gz

MAINTAINER=	sumikawa@FreeBSD.org

DIST_SUBDIR=	kbanner
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
ALL_TARGET=	kbanner
MAN1=		kbanner.1

TMPFILE=	kbanner.uu.txt
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	-cd
EXTRACT_AFTER_ARGS=	>> ${TMPFILE}

post-extract:
	cd ${WRKDIR} && ${SED} '/^END/,/^BEGIN/d' ${TMPFILE} | uudecode -p | tar zxvf -

.include <bsd.port.mk>
