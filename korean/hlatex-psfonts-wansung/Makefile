# New ports collection makefile for:    HLaTeX PS fonts-wansungstd
# Version required:             0.98
# Date created:                 Sun Aug  9 18:05:29 KST 1998
# Whom:                         CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=               HLaTeXpsfonts-wansung-0.98
PKGNAME=                ko-HLaTeXpsfonts-${HLATEX_ENCODING}std-0.98
CATEGORIES=             korean print
MASTER_SITES=           ftp://ftp.linguistik.uni-erlangen.de/pub/HLaTeX/${HLATEX_ENCODING}/
DISTFILES=              ${HLATEX_PSFONTS_BASE}

MAINTAINER=             cjh@kr.freebsd.org

# it depends ko-HLaTeX.
RUN_DEPENDS=		${PREFIX}/share/texmf/doc/latex/hlatex/wansung.ks:${PORTSDIR}/korean/hlatex-${HLATEX_ENCODING}std
BUILD_DEPENDS=		${PREFIX}/share/texmf/doc/latex/hlatex/wansung.ks:${PORTSDIR}/korean/hlatex-${HLATEX_ENCODING}std

# just install directly
EXTRACT_ONLY=
NO_BUILD=		yes
USE_BZIP2=		yes
DIST_SUBDIR=            hlatex98        # too many distfiles

TEXMF=			${PREFIX}/share/texmf
# default encoding
HLATEX_ENCODING=        wansung
# default font. includes complete Myoungjo and Gothic fonts.
HLATEX_PSFONTS_BASE     = pkmj.tar.bz2 pkgt.tar.bz2 \
			  pshanja-myoungjo.tar.bz2 pshanja-gothic.tar.bz2 \
			  phsym.tar.bz2 ptaza.tar.bz2

# it is a trick
pre-extract:
	${MKDIR} ${WRKDIR}

# Installation according to readme.ks
do-install:
	cd ${TEXMF}/fonts/; \
	for fonts in ${HLATEX_PSFONTS_BASE}; \
	do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
			${_DISTDIR}/$$fonts ${EXTRACT_AFTER_ARGS}; \
	done; \
	${PREFIX}/bin/texhash

.include <bsd.port.mk>
