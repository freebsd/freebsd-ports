# New ports collection makefile for:	pTeX
# Date created:		05 Oct 1997
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	ptex
PORTVERSION=	3.1.2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/
PKGNAMEPREFIX=	ja-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
DIST_SUBDIR=	teTeX

MAINTAINER=	max@FreeBSD.org
COMMENT=	Japanese specific files for ASCII Japanese pTeX

BUILD_DEPENDS=	${PREFIX}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-base
RUN_DEPENDS=	${PREFIX}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-base

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${KANJICODE}
WRKSRC=	${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/tetex-src-${TETEX_VERSION}/texk/web2c/${SRCDIR}
ALL_TARGET=	default

KANJICODE?=	euc
SRCDIR=		ptex-${PORTVERSION}
TETEX_VERSION=	2.0.1
BINARIES=	ptex pdvitype jbibtex pltotf tftopl

pre-extract:
	@${ECHO} "The default kanji code is ${KANJICODE}."
	@${ECHO} "You can change the kanji code at ptex runtime with the -kanji option."
	@${ECHO} "e.g. ptex -kanji=sjis"
	@${ECHO} "If you would like to change the default kanji code, run make as follows:"
	@${ECHO} "    make KANJICODE=sjis"
	@${ECHO} "for Shift-JIS.  KANJICODE can be one of sjis, jis or euc."
	@sleep 10
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/.build_done.ja-ptex-base-${PORTVERSION})
	@(cd ${.CURDIR}/../ptex-base; \
	  ${SETENV} ${MAKE_ENV} ${MAKE})
.endif

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${SRCDIR} ${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/tetex-src-${TETEX_VERSION}/texk/web2c

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for bin in ${BINARIES}
	@/usr/bin/strip ${PREFIX}/bin/${bin}
.endfor
	@${LN} -sf ptex ${PREFIX}/bin/platex
	@${PREFIX}/bin/mktexlsr ${PREFIX}/share/texmf

pre-clean:
	@${RM} -rf ${WRKSRC}

.include <bsd.port.mk>
