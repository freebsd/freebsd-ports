# New ports collection makefile for:    dvipsk + jpatch
# Date created:         25 Aug 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dvipsk
PORTVERSION=	5.78a
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/ \
		ftp://ftp.center.osaka-u.ac.jp/CTAN/dviware/dvipsk/ \
		ftp://ftp.riken.go.jp/pub/CTAN/dviware/dvipsk/ \
		ftp://ftp.u-aizu.ac.jp/pub/tex/CTAN/dviware/dvipsk/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-jpatch-p1.4d.tar.gz

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

RUN_DEPENDS=	MakeTeXPK:${PORTSDIR}/japanese/ptex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of dvipsk-*

DIST_SUBDIR=	ptex
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_install="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}"
SCRIPTS_ENV=	MV=${MV} SED=${SED}
MAN1=		dvips.1 afm2tfm.1

TEXMF=		${PREFIX}/share/texmf
DVIPSDIR=	${TEXMF}/dvips
TEXDIR=		${TEXMF}/tex
BINARIES=	dvips afm2tfm
BASE_FILES=	config.ps cmfonts.map cyrfonts.map eufonts.map lafonts.map
CONTRIB_DIRS=	afm-extra bbfig configs psfig volker
CONTRIB_FILES=	MakeTeXPK.pl PSTricks colorsep.pro config.proto crop.lpr \
		timesmat.sty whichinpath afm-extra/*.ed bbfig/bb* \
		configs/*[^g] psfig/README psfig/lprep* volker/*
PLAIN_MACROS=	psfig/psfig.tex psfntmac/ps_plain.tex
LATEX209_MACROS=latex209/*.sty psfntmac/ps_lfonts.tex pspic/*
DOCS=		../README.jpatch dvipsk/README \
		dvipsk/dvips.texi dvipsk/dvips.help

pre-patch:
	@${PATCH} -p -s -d ${WRKSRC} < ${WRKDIR}/dvipsk.patch

post-build:
	@(\
	  cd ${WRKSRC}/dvipsk/contrib ; \
	  ../squeeze < colorsep.lpro > colorsep.pro \
	)

post-install:
	@for i in ${BINARIES} ; do \
	    strip ${PREFIX}/bin/$$i ; \
	done
	@for i in ${CONTRIB_DIRS} ; do \
	  ${MKDIR} ${DVIPSDIR}/contrib/$$i ; \
	done
	@${MKDIR} ${TEXDIR}/latex209/dvips
	@(\
	  cd ${WRKSRC}/dvipsk ; \
	  for i in ${BASE_FILES} ; do \
	    ${INSTALL_DATA} $$i ${DVIPSDIR}/base ; \
	  done ; \
	  cd ${WRKSRC}/dvipsk/contrib ; \
	  for i in ${CONTRIB_FILES} ; do \
	    ${INSTALL_DATA} $$i ${DVIPSDIR}/contrib/$$i ; \
	  done ; \
	  for i in ${PLAIN_MACROS} ; do \
	    ${INSTALL_DATA} $$i ${TEXDIR}/plain/dvips ; \
	  done ; \
	  for i in ${LATEX209_MACROS} ; do \
	    ${INSTALL_DATA} $$i ${TEXDIR}/latex209/dvips ; \
	  done \
	)
# rebuild tex ls-R file
	mktexlsr
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dvips
	@for i in ${DOCS} ; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/dvips ; \
	done
	@${LN} -fs ${DVIPSDIR}/contrib ${PREFIX}/share/doc/dvips/contrib
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
