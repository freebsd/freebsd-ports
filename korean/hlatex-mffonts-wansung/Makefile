# New ports collection makefile for:    HLaTeX Wansung fonts
# Date created:                 2 Jul 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HLaTeX-${FONT_TYPE}fonts-${FONT_ENCODING}
PORTVERSION=	0.98
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.linguistik.uni-erlangen.de/pub/hangul/HLaTeX/packed/unsupported/
DISTFILES=	${HLATEX_FONTS_BASE}
DIST_SUBDIR=	hlatex
EXTRACT_ONLY=

MAINTAINER=	cjh@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/texmf/doc/latex/hlatex/wansung.ks:${PORTSDIR}/korean/hlatex-wansung

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
USE_BZIP2=	YES

TEXMF=		${PREFIX}/share/texmf
FONT_ENCODING?=	wansung
FONT_TYPE?=	mf

# default font. includes complete Myoungjo and Gothic fonts.
HLATEX_FONTS_BASE?= common.tar.bz2 \
		   wsmj.tar.bz2 wsgt.tar.bz2 \
		   hanja-myoungjo.tar.bz2 hanja-gothic.tar.bz2 \
		   hsym.tar.bz2 taza.tar.bz2

do-install:
	cd ${TEXMF}/fonts/; \
	for fonts in ${HLATEX_FONTS_BASE}; \
	do \
		${EXTRACT_CMD} \
			${EXTRACT_BEFORE_ARGS} \
			${_DISTDIR}/$$fonts ${EXTRACT_AFTER_ARGS}; \
	done
	# rehash ls-R
	${PREFIX}/bin/texhash

.include <bsd.port.mk>
