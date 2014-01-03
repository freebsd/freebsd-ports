# Created by: David O'Brien (obrien@FreeBSD.org)
# $FreeBSD$

PORTNAME=	gb2ps
PORTVERSION=	2.02
CATEGORIES=	chinese print
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/print/:sw  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/fonts/gb/misc/:font
DISTNAME=	gb2ps.2.02
DISTFILES=	${DISTNAME}.tar.gz:sw  \
		csong24.ccf.gz:font ckai24.ccf.gz:font cfang24.ccf.gz:font \
		chei24.ccf.gz:font cfan24.ccf.gz:font

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts Chinese GB (simple) encoded text to PostScript

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/GB2PS

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/chinese/gb
	${INSTALL_PROGRAM} ${WRKSRC}/gb2ps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cover.ps ${STAGEDIR}${PREFIX}/share/chinese
.for font in csong24.ccf ckai24.ccf cfang24.ccf chei24.ccf cfan24.ccf
	${GUNZIP_CMD} -c ${DISTDIR}/${font}.gz > ${STAGEDIR}${PREFIX}/share/chinese/gb/${font}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/gb2ps
	${INSTALL_DATA} ${WRKSRC}/gb2ps.help ${STAGEDIR}${PREFIX}/share/doc/gb2ps
.endif

.include <bsd.port.mk>
