# New ports collection makefile for:	pTeX
# Date created:		05 Oct 1997
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	ptex
PORTVERSION=	3.1.3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/
PKGNAMEPREFIX=	ja-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
DIST_SUBDIR=	teTeX

MAINTAINER=	max@FreeBSD.org
COMMENT=	Japanese specific files for ASCII Japanese pTeX

BUILD_DEPENDS=	${LOCALBASE}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-base
RUN_DEPENDS=	${LOCALBASE}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-base

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${KANJICODE}
WRKSRC=	${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/tetex-src-${TETEX_VERSION}/texk/web2c/${SRCDIR}
ALL_TARGET=	default

KANJICODE?=	euc
SRCDIR=		ptex-src-${PORTVERSION}
TETEX_VERSION=	2.0.2
BINARIES=	ptex pdvitype jbibtex pltotf tftopl

pre-extract:
	@${ECHO_MSG} "The default kanji code is ${KANJICODE}."
	@${ECHO_MSG} "You can change the kanji code at ptex runtime with the -kanji option."
	@${ECHO_MSG} "e.g. ptex -kanji=sjis"
	@${ECHO_MSG} "If you would like to change the default kanji code, run make as follows:"
	@${ECHO_MSG} "    make KANJICODE=sjis"
	@${ECHO_MSG} "for Shift-JIS.  KANJICODE can be one of sjis, jis or euc."
	@sleep 10

pre-configure:
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/.build_done.ja-ptex-base-${PORTVERSION})
	@(cd ${.CURDIR}/../ptex-base; \
	  ${SETENV} ${MAKE_ENV} ${MAKE})
.endif
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${SRCDIR} ${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/tetex-src-${TETEX_VERSION}/texk/web2c

pre-install:
	@if [ -L ${PREFIX}/share/texmf/web2c/texmf.cnf ]; then \
	  ${RM} ${PREFIX}/share/texmf/web2c/texmf.cnf; \
	  fi

post-install:
.for bin in ${BINARIES}
	@${STRIP_CMD} ${PREFIX}/bin/${bin}
.endfor
	@${LN} -sf ptex ${PREFIX}/bin/platex
	@${PREFIX}/bin/mktexlsr ${PREFIX}/share/texmf

pre-clean:
	@${RM} -rf ${WRKSRC}

.include <bsd.port.mk>
