# ex:ts=8
# Ports collection makefile for:  gb2ps
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	gb2ps
PORTVERSION=	2.02
CATEGORIES=	chinese print
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/print/  \
		ftp://ftp.ifcss.org/pub/software/fonts/gb/misc/  \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/print/  \
		ftp://ftp.edu.tw/Chinese/ifcss/software/fonts/gb/misc/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/print/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/fonts/gb/misc/
DISTNAME=	gb2ps.2.02
DISTFILES=	${DISTNAME}.tar.gz  \
		csong24.ccf.gz ckai24.ccf.gz cfang24.ccf.gz chei24.ccf.gz \
		cfan24.ccf.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts Chinese GB (simple) encoded text to PostScript

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/GB2PS

do-install:
	@${MKDIR} ${PREFIX}/share/chinese/gb
	${INSTALL_PROGRAM} ${WRKSRC}/gb2ps ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cover.ps ${PREFIX}/share/chinese
.for font in csong24.ccf ckai24.ccf cfang24.ccf chei24.ccf cfan24.ccf
	${GUNZIP_CMD} -c ${DISTDIR}/${font}.gz > ${PREFIX}/share/chinese/gb/${font}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gb2ps
	${INSTALL_DATA} ${WRKSRC}/gb2ps.help ${PREFIX}/share/doc/gb2ps
.endif

.include <bsd.port.mk>
