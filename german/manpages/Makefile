# New ports collection makefile for: German manpages
# Version required:     1.0
# Date created:         29 September 1997
# Whom:                 wosch
#
# $Id: Makefile,v 1.3 1997/09/30 06:51:09 asami Exp $
#

DISTNAME=       de-manpages-1.0
CATEGORIES=	german
MASTER_SITES=   ftp://ftp.Infodrom.North.DE/pub/Linux/Devel/manpages-de/
DISTFILES=	${manpages}.tgz

MAINTAINER=     wosch@FreeBSD.org

LANG=		de_DE.ISO_8859-1
NO_WRKSUBDIR=	YES
NO_CHECKSUM=	YES

mandir=		${PREFIX}/man/${LANG}
manpages=	manpages-de

do-build:
	ln -s ${WRKSRC}/${manpages} ${WRKSRC}/de-man
	makewhatis ${WRKSRC}/de-man
.if !defined(NOMANCOMPRESS)
	${GZIP_CMD} -r ${WRKSRC}/${manpages}/man* || exit 0
.endif

do-install:
	cd ${WRKSRC}/${manpages}; \
	${EXTRACT_CMD} cf - . | \
		(cd ${mandir}; ${EXTRACT_CMD} xf - )

post-install:
	find ${WRKSRC}/${manpages} -type f -print | \
		sed "s%${WRKSRC}/${manpages}%man/${LANG}%" > \
	   ${WRKSRC}/PLIST && cp -f ${WRKSRC}/PLIST ${.CURDIR}/pkg/PLIST

.include <bsd.port.mk>
