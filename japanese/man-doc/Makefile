# New ports collection makefile for:	Japanese man documents
# Version required:	1.0
# Date created:		6 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id$
#

DISTNAME=	jp-man-doc-1.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/FreeBSD/jpman/freebsd2.1-jman-0.1/fbsd-jman/
DISTFILES=	man1.tar.gz man8.tar.gz

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

NO_EXTRACT=	yes
NO_BUILD=	yes
NO_WRKDIR=	yes

JMANDIR=	${PREFIX}/man/ja_JP.EUC

do-install:
	@(cd ${JMANDIR}; \
	tar zxf ${DISTDIR}/man1.tar.gz; \
	tar zxf ${DISTDIR}/man8.tar.gz)
.if !defined(NOMANCOMPRESS)
	@(cd ${JMANDIR}/man1; \
	for f in *.1; do \
		${GZIP_CMD} $$f; \
	done )
	@(cd ${JMANDIR}/man8; \
	for f in *.8; do \
		${GZIP_CMD} $$f; \
	done )
.endif

.include <bsd.port.mk>
