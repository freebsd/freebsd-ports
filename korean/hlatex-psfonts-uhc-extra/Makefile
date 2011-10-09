# New ports collection makefile for:    HLaTeX PS fonts(extra)
# Date created:                 2 Jul 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HLaTeX-psfonts-${HLATEX_ENCODING}-extra
PORTVERSION=	0.99
PORTREVISION=	3
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/hlatex/
DISTFILES=	${HLATEX_PSFONTS_EXTRA}
DIST_SUBDIR=	hlatex
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extra Korean PostScript font collection for HLaTeX(UHC encoding)

DEPRECATED=	Depends on korean/hlatex, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

RUN_DEPENDS=	hbibtex:${PORTSDIR}/korean/hlatex

# just install directly
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

TEXMF=		${PREFIX}/share/texmf

# default encoding
HLATEX_ENCODING=        uhc

# extra fonts
HLATEX_PSFONTS_EXTRA=	uhc-graphic.tar.gz uhc-bom.tar.gz \
			uhc-gungseo.tar.gz uhc-pilgi.tar.gz \
			uhc-pen.tar.gz uhc-shinmun.tar.gz \
			uhc-yetgul.tar.gz uhc-jamo.tar.gz

# Installation according to readme.ks
do-install:
	cd ${TEXMF}/fonts/; \
	for fonts in ${HLATEX_PSFONTS_EXTRA}; \
	do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
			${_DISTDIR}/$$fonts ${EXTRACT_AFTER_ARGS}; \
	done; \
	${PREFIX}/bin/texhash

.include <bsd.port.mk>
