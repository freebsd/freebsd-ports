# New ports collection makefile for: German manpages
# Date created:         29 September 1997
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	manpages
PORTVERSION=	1.0
CATEGORIES=	german
MASTER_SITES=   http://wolfram.schneider.org/src/
DISTFILES=	${manpages}.tgz

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	German GNU and Linux manual pages

LANG=		de.ISO8859-1
NO_WRKSUBDIR=	YES
PLIST=		${WRKSRC}/PLIST

mandir=		${PREFIX}/man/${LANG}
manpages=	manpages-de

do-build:
	${LN} -s ${WRKSRC}/${manpages} ${WRKSRC}/de-man
	makewhatis ${WRKSRC}/de-man
.if !defined(NOMANCOMPRESS)
	${GZIP_CMD} -r ${WRKSRC}/${manpages}/man* || exit 0
.endif

pre-install:
	find ${WRKSRC}/${manpages} -type f -print | \
		 ${SED} "s%${WRKSRC}/${manpages}%man/${LANG}%" > ${PLIST}

do-install:
	cd ${WRKSRC}/${manpages}; \
	${TAR} cf - . | \
		(cd ${mandir}; ${TAR} xf - )

.include <bsd.port.mk>
