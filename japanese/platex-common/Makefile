# New ports collection makefile for:	pLaTeX
# Version required:	?
# Date created:		5 Nov 1995
# Whom:			Hideaki Ohmon <ohmon@sfc.keio.ac.jp>
#
# $Id: Makefile,v 1.16 1997/09/14 21:35:44 max Exp $
#

DISTNAME=	platex2e
PKGNAME=	ja-platex2e-97.02.01
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex2e/1997-02-01/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	base-9612.tar.gz ecfonts-1.0.tar.gz

MAINTAINER=	max@FreeBSD.ORG

BROKEN=		"This port is out of date and must be modified to use the latest pTeX"
BUILD_DEPENDS=  ptex:${PORTSDIR}/japanese/ptex2
RUN_DEPENDS=    ptex:${PORTSDIR}/japanese/ptex2

WRKSRC=		${WRKDIR}/9702
DIST_SUBDIR=	platex2e
NO_BUILD=	yes

pre-fetch:
.if !defined(KANJI-CODE)
	@echo "You can set KANJI-CODE value to JIS, SJIS or EUC."
	@echo "Now JIS is used as default."
.if !defined(BATCH) && !defined(FOR_CDROM)
	@echo -n "Is JIS OK? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
	        return 0; \
	        ;; \
	    *) \
		echo "Ok, please rerun make with preferred KANJI-CODE specification"; \
		echo " like following example."; \
		echo "	make KANJI-CODE=EUC"; \
	        return 1; \
	        ;; \
	  esac)
.endif
KANJI-CODE=	JIS
.endif
.if ${KANJI-CODE} == JIS
PLIB_FILE=	pl9702j.tar.gz
.elif ${KANJI-CODE} == SJIS
PLIB_FILE=	pl9702s.tar.gz
.elif ${KANJI-CODE} == EUC
PLIB_FILE=	pl9702e.tar.gz
.elifdef KANJI-CODE
	@echo "Error: invalid value for KANJI-CODE: \"${KANJI-CODE}\""
	@echo "Possible values are: JIS (default), SJIS, EUC."
	@false
.endif
.if !defined(FOR_CDROM)
DISTFILES+=	${PLIB_FILE}
.else
DISTFILES+=	pl9702j.tar.gz pl9702s.tar.gz pl9702e.tar.gz
.endif
EXTRACT_ONLY=	${PLIB_FILE}

do-install:
	@${RM} -f ${PREFIX}/lib/texmf/tex/latex2e/base/*
	@${RM} -f ${PREFIX}/lib/texmf/tex/platex2e/base/*
	@tar -C ${PREFIX}/lib/texmf/fonts/public -zx \
	  -f ${DISTDIR}/${DIST_SUBDIR}/ecfonts-1.0.tar.gz
	@tar -C ${PREFIX}/lib/texmf/tex/latex2e -zx \
	  -f ${DISTDIR}/${DIST_SUBDIR}/base-9612.tar.gz
	(cd ${PREFIX}/lib/texmf/tex/latex2e/base; \
	  initex unpack.ins; \
	  yes | initex ec.ins; \
	  initex latex.ltx; \
	  mv -f latex.fmt ${PREFIX}/lib/texmf/ini)
	ln -fs ${PREFIX}/bin/virtex ${PREFIX}/bin/latex
	@${MKDIR} ${PREFIX}/lib/texmf/tex/platex2e/base
	@${CP} -R ${WRKSRC}/* ${PREFIX}/lib/texmf/tex/platex2e/base
	(cd ${PREFIX}/lib/texmf/tex/platex2e/base; \
	  iniptex plcore.ins; \
	  iniptex platex.ltx; \
	  mv -f platex.fmt ${PREFIX}/lib/texmf/ini)
	ln -fs ${PREFIX}/bin/virptex ${PREFIX}/bin/platex

.include <bsd.port.mk>
