# New ports collection makefile for:	Japanese man documents
# Version required:	2.2.2g
# Date created:		6 January 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.14 1997/12/08 09:26:42 max Exp $
#

DISTNAME=	jpman-${VERSION}g
PKGNAME=	ja-man-doc-${VERSION}g
CATEGORIES=	japanese
MASTER_SITES=	ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/man-jp/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jpman-${VERSION}
SCRIPTS_ENV=	TMPL_FILE=${TMPL_FILE} PKGDIR=${PKGDIR} AWK=${AWK} \
		CAT=${CAT} ECHO=${ECHO} GZIP_CMD="${GZIP_CMD}" \
		RM=${RM} SED=${SED} 

VERSION=	2.2.2
TMPL_FILE=	install-man

do-install:
.if !defined(NOMANCOMPRESS)
	@${SETENV} PREFIX=${PREFIX} LANG="${LANG}" ${SH} \
		${FILESDIR}/install-man MANCOMPRESSED
.else
	@${SETENV} PREFIX=${PREFIX} LANG="${LANG}" ${SH} \
		${FILESDIR}/install-man NOMANCOMPRESS
.endif

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

pre-clean:
	@${RM} -f ${FILESDIR}/${TMPL_FILE} ${PKGDIR}/PLIST

.include <bsd.port.mk>
