# ex:ts=8
# Ports collection makefile for:  gbscript
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	gbscript
PORTVERSION=	1.11
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/print/  \
		ftp://ftp.ifcss.org/pub/software/fonts/gb/misc/  \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/print/  \
		ftp://ftp.edu.tw/Chinese/ifcss/software/fonts/gb/misc/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/print/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/fonts/gb/misc/
DISTFILES=	gbscript-1.11.tar.gz cclib.24

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts GB simplified Chinese text to PostScript

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
MAKEFILE=	makefile
CFLAG+=		-DPROLOGUE_PATH=\"${PREFIX}/share/chinese/gb\"

do-install:
	@${MKDIR} ${PREFIX}/share/chinese/gb
	${INSTALL_PROGRAM} ${WRKSRC}/gbscript ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gbscript.pro ${PREFIX}/share/chinese/gb
	${INSTALL_DATA} ${DISTDIR}/cclib.24 ${PREFIX}/share/chinese/gb

.include <bsd.port.mk>
