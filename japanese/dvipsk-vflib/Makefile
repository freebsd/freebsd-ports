# New ports collection makefile for:    dvipsk + jpatch + vflib-patch
# Version required:     5.78a + p1.4 + 1.1alpha
# Date created:         25 Aug 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $Id: Makefile,v 1.2 1998/10/07 06:11:41 asami Exp $
#

DISTNAME=	dvipsk-5.78a
PKGNAME=	ja-dvipsk-vflib-5.78a
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex218/ \
		ftp://ftp.center.osaka-u.ac.jp/CTAN/dviware/dvipsk/ \
		ftp://ftp.riken.go.jp/pub/CTAN/dviware/dvipsk/ \
		ftp://ftp.u-aizu.ac.jp/pub/tex/CTAN/dviware/dvipsk/ \
		http://math.shinshu-u.ac.jp/~nakayama/howto/tex/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} dvipsk-jpatch-p1.4.tar.gz \
		dvipsk-vflib-1.1alpha.patch.tgz

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

RUN_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common \
		${PREFIX}/share/fonts/vf-a2bk:${PORTSDIR}/japanese/vftool
LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

MANUAL_PACKAGE_BUILD=	incompatible with other versions of dvipsk-*

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_install="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}"
MAKE_FLAGS=	XCFLAGS="-I${PREFIX}/include" XLOADLIBES="-L${PREFIX}/lib"
MAN1=		dvips.1 afm2tfm.1

TEXMF=		${PREFIX}/share/texmf
DVIPSDIR=	${TEXMF}/dvips
TEXDIR=		${TEXMF}/tex
BINARIES=	dvips afm2tfm
BACKUP_FILES=	base/asex.enc base/psfonts.map config/config.ps
BASE_FILES=	vffonts.pro cmfonts.map cyrfonts.map eufonts.map lafonts.map \
		reencode/asex.enc
CONTRIB_DIRS=	afm-extra bbfig configs psfig volker
CONTRIB_FILES=	MakeTeXPK.pl PSTricks colorsep.pro config.proto crop.lpr \
		timesmat.sty whichinpath afm-extra/*.ed bbfig/bb* \
		configs/*[^g] psfig/README psfig/lprep* volker/*
PLAIN_MACROS=	psfig/psfig.tex psfntmac/ps_plain.tex
LATEX209_MACROS=latex209/*.sty psfntmac/ps_lfonts.tex pspic/*
DOCS=		../README.jpatch ../README.vflib dvipsk/README \
		dvipsk/dvips.texi dvipsk/dvips.help

pre-patch:
	@${PATCH} -p -s -d ${WRKSRC} < ${WRKDIR}/dvipsk.patch
	@${PATCH} -p -s -d ${WRKSRC} < ${WRKDIR}/dvipsk-vflib-1.1alpha.patch

post-build:
	@(\
	  cd ${WRKSRC}/dvipsk/contrib ; \
	  ../squeeze < colorsep.lpro > colorsep.pro \
	)

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ] ; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir ; \
	fi
	@for i in ${BACKUP_FILES} ; do \
	  if [ -f ${DVIPSDIR}/$$i ] ; then \
	    ${MV} ${DVIPSDIR}/$$i ${DVIPSDIR}/$$i.bak ; \
	  fi ; \
	done

post-install:
	@for i in ${BINARIES} ; do \
	    strip ${PREFIX}/bin/$$i ; \
	done
	@${MKDIR} ${DVIPSDIR}/config
	@for i in ${CONTRIB_DIRS} ; do \
	  ${MKDIR} ${DVIPSDIR}/contrib/$$i ; \
	done
	@${MKDIR} ${TEXDIR}/latex209/dvips
	@(\
	  cd ${WRKSRC}/dvipsk ; \
	  for i in ${BASE_FILES} ; do \
	    ${INSTALL_DATA} $$i ${DVIPSDIR}/base ; \
	  done ; \
	  ${INSTALL_DATA} config.ps ${DVIPSDIR}/config ; \
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dvips
	@for i in ${DOCS} ; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/dvips ; \
	done
	@${LN} -fs ${DVIPSDIR}/contrib ${PREFIX}/share/doc/dvips/contrib
.endif
.if defined(BATCH)
	@${SETENV} PKG_PREFIX=${PREFIX} \
	  ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL BATCH
.else
	@${SETENV} PKG_PREFIX=${PREFIX} \
	  ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
