# New ports collection makefile for: German manpages
# Version required:     1.0
# Date created:         29 September 1997
# Whom:                 wosch
#
# $Id: Makefile,v 1.7 1998/08/25 01:25:05 asami Exp $
#

DISTNAME=       de-manpages-1.0
CATEGORIES=	german
MASTER_SITES=   http://www.freebsd.org/~wosch/src/ \
		ftp://ftp.Infodrom.North.DE/pub/Linux/Devel/manpages-de/
DISTFILES=	${manpages}.tgz

MAINTAINER=     wosch@FreeBSD.org

LANG=		de_DE.ISO_8859-1
NO_WRKSUBDIR=	YES
PLIST=		${WRKSRC}/PLIST

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
	${TAR} cf - . | \
		(cd ${mandir}; ${TAR} xf - )
	find ${WRKSRC}/${manpages} -type f -print | \
		 ${SED} "s%${WRKSRC}/${manpages}%man/${LANG}%" > \
	   ${WRKSRC}/PLIST

.include <bsd.port.mk>
