# New ports collection makefile for:	Japanese man documents
# Version required:	2.2.2g
# Date created:		6 January 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.15 1997/12/10 04:43:15 max Exp $
#

DISTNAME=	jpman-${VERSION}g
PKGNAME=	ja-man-doc-2.2.2g
CATEGORIES=	japanese
MASTER_SITES=	ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/man-jp/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jpman-${VERSION}
SCRIPTS_ENV=	TMPL_FILE=${TMPL_FILE} PKGDIR=${PKGDIR} AWK=${AWK} \
		CAT=${CAT} ECHO=${ECHO} GZIP_CMD="${GZIP_CMD}" \
		RM=${RM} SED=${SED} 
PLIST=		${WRKSRC}/PLIST

VERSION=	2.2.2
TMPL_FILE=	install-man

do-install:
.if !defined(NOMANCOMPRESS)
	@${SETENV} PREFIX=${PREFIX} LANG="${LANG}" ${SH} \
		${WRKSRC}/${TMPL_FILE} MANCOMPRESSED
.else
	@${SETENV} PREFIX=${PREFIX} LANG="${LANG}" ${SH} \
		${WRKSRC}/${TMPL_FILE} NOMANCOMPRESS
.endif

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
