# New ports collection makefile for:	Japanese man documents
# Version required:	2.2.2c
# Date created:		6 January 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.4 1997/02/12 11:00:45 asami Exp $
#

DISTNAME=	jpman-${VERSION}c
PKGNAME=	jp-man-doc-${VERSION}c
CATEGORIES=	japanese
MASTER_SITES=	ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/man-jp/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

NO_BUILD=	yes

VERSION=	2.2.2
JPMANDIR=	jpman-${VERSION}
WRKSRC=		${WRKDIR}/${JPMANDIR}

do-install:
.if !defined(NOMANCOMPRESS)
	@${SETENV} LANG="${LANG}" PREFIX=${PREFIX} WRKSRC=${WRKSRC} \
		PKGDIR=${PKGDIR} DISTDIR=${DISTDIR} DISTFILES=${DISTFILES} \
		JPMANDIR=${JPMANDIR} EXTRACT_CMD=${EXTRACT_CMD} \
		ECHO=${ECHO} RM=${RM} AWK=${AWK} \
		GZIP_CMD="${GZIP_CMD}" SED=${SED} \
		INSTALL_MAN="${INSTALL_MAN}" /bin/sh \
		${FILESDIR}/install-man MANCOMPRESSED  
.else
	@${SETENV} LANG="${LANG}" PREFIX=${PREFIX} WRKSRC=${WRKSRC} \
		PKGDIR=${PKGDIR} DISTDIR=${DISTDIR} \
		DISTFILES=${DISTFILES} JPMANDIR=${JPMANDIR} \
		EXTRACT_CMD=${EXTRACT_CMD} ECHO=${ECHO} RM=${RM} \
		AWK=${AWK} GZIP_CMD="${GZIP_CMD}" SED=${SED} \
		INSTALL_MAN="${INSTALL_MAN}" /bin/sh \
		${FILESDIR}/install-man NOMANCOMPRESS  
.endif

pre-clean:
	@${RM} -f ${PKGDIR}/PLIST

.include <bsd.port.mk>
