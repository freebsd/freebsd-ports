# New ports collection makefile for: German manpages
# Version required:     1.0
# Date created:         29 September 1997
# Whom:                 wosch
#
# $Id: Makefile,v 1.2 1997/09/29 18:04:04 wosch Exp $
#

DISTNAME=       de-manpages-1.0
CATEGORIES=	german
MASTER_SITES=   ftp://ftp.Infodrom.North.DE/pub/Linux/Devel/manpages-de/
DISTFILES=	${manpages}.tgz

MAINTAINER=     wosch@FreeBSD.org

LANG=		de_DE.ISO_8859-1
NO_WRKSUBDIR=	YES
NO_PACKAGE=	YES

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

.include <bsd.port.mk>
