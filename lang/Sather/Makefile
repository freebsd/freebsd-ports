# New ports collection makefile for:    Sather
# Version required:     1.0.5
# Date created:         Mon Oct 31 22:04:12 PST 1994
# Whom:                 hsu
#
# $FreeBSD$
#

DISTNAME=       Sather-1.0.5
PKGNAME=        sather-1.0.5
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.icsi.berkeley.edu/pub/sather/  \
		ftp://ftp.sterling.com/programming/languages/sather/  \
		ftp://ftp.uni-muenster.de/pub/languages/sather/  \
		ftp://ftp.nis.co.jp/pub/lang/sather/  \
		ftp://ftp.th-darmstadt.de/pub/programming/languages/sather/  \
		ftp://ftp.sra.co.jp/pub/lang/sather/  \
		ftp://ftp.infomagic.com/pub/mirrors/.mirror14/languages/sather/

MAINTAINER=	obrien@FreeBSD.org

BROKEN_ELF=	gcc: ../../System/GC/gc.a: No such file or directory

WRKSRC=		${WRKDIR}/Sather
ALL_TARGET=	testall
MAN1=		cs.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Compiler/cs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/cs.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/sather
	${INSTALL_DATA} ${WRKSRC}/Doc/License ${PREFIX}/share/doc/sather
.if !defined(NOPORTDOCS)
.for file in Bugs Changes Contributing FAQ README manual.ps
	${INSTALL_DATA} ${WRKSRC}/Doc/${file} ${PREFIX}/share/doc/sather
.endfor
.endif

.include <bsd.port.mk>
