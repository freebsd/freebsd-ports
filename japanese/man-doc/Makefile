# New ports collection makefile for:	Japanese man documents
# Version required:	0.2
# Date created:		1 January 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/12/07 13:24:42 asami Exp $
#

DISTNAME=	jp-man-doc-0.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://jp.freebsd.org/pub/FreeBSD/man-jp/
DISTFILES=	jpman-0.2.961227.tgz

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

NO_BUILD=	yes
JPMANDIR=	jpman-0.2
WRKSRC=		${WRKDIR}/${JPMANDIR}

do-install:
.if !defined(NOMANCOMPRESS)
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} PKGDIR=${PKGDIR} DISTDIR=${DISTDIR} DISTFILES=${DISTFILES} JPMANDIR=${JPMANDIR} EXTRACT_CMD=${EXTRACT_CMD} ECHO=${ECHO} RM=${RM} AWK=${AWK} GZIP_CMD="${GZIP_CMD}" SED=${SED} INSTALL_MAN="${INSTALL_MAN}" /bin/sh ${FILESDIR}/install-man MANCOMPRESSED
.else
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} PKGDIR=${PKGDIR} DISTDIR=${DISTDIR} DISTFILES=${DISTFILES} JPMANDIR=${JPMANDIR} EXTRACT_CMD=${EXTRACT_CMD} ECHO=${ECHO} RM=${RM} AWK=${AWK} GZIP_CMD="${GZIP_CMD}" SED=${SED} INSTALL_MAN="${INSTALL_MAN}" /bin/sh ${FILESDIR}/install-man NOMANCOMPRESS
.endif

pre-clean:
	@${RM} -f ${PKGDIR}/PLIST

.include <bsd.port.mk>
