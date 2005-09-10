# New ports collection makefile for:    mendexk-euc
# Date created:         1 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mendexk
PORTVERSION=	2.6c
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/:1 \
		${MASTER_SITE_TEX_CTAN}
DISTFILES=	${PORTNAME}${PORTVERSION}${EXTRACT_SUFX}:1 \
		${TETEX_SRC}${EXTRACT_SUFX}
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Index formatter for Japanese

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${KANJICODE}
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV=	INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
USE_GMAKE=	yes
ALL_TARGET=	mendex
MAN1=		mendex.1
MANLANG=	ja

WRKSRC=		${WRKSRC_TETEX}/texk/${PORTNAME}${PORTVERSION}
WRKSRC_MENDEX=	${WRKDIR}/${PORTNAME}${PORTVERSION}
WRKSRC_TETEX=	${WRKDIR}/${TETEX_SRC}
TETEX_SRC=	tetex-src-3.0

KANJICODE?=	EUC

post-extract:
	${MV} ${WRKSRC_MENDEX} ${WRKSRC_TETEX}/texk

pre-configure:
	cd ${WRKSRC_TETEX} && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
			--prefix=${PREFIX} \
			--disable-multiplatform \
			--without-texinfo --without-dialog \
			--with-system-ncurses --with-system-zlib \
			--without-xdvik --without-oxdvik \
			--without-dvipsk --without-odvipsk \
			--without-x11 --without-dvipdfm \
			--without-pdftex --without-pdfetex --without-pdfxtex \
			--without-omega --without-eomega \
			--without-etex
	cd ${WRKSRC}/../kpathsea && ${SETENV} ${MAKE_ENV} ${MAKE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
