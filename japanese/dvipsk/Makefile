# New ports collection makefile for:    dvipsk + jpatch
# Version required:     5.66a
# Date created:         25 Aug 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $Id$
#

DISTNAME=	dvipsk-5.66a
PKGNAME=	ja-dvipsk-5.66a
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex215/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex215/web2c/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} dvipsk-jpatch-p1.3b.tar.gz

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

RUN_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common \
		${PREFIX}/share/fonts/vf-a2bk:${PORTSDIR}/japanese/vftool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_install="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}"
MAN1=		dvips.1 afm2tfm.1

TEXMF=		${PREFIX}/share/texmf
DVIPSDIR=	${TEXMF}/dvips
TEXDIR=		${TEXMF}/tex
BINARIES=	dvips afm2tfm
CONTRIB_FILES=	2a4.ps bb.ps bbfig config.fax config.lino config.lj2p \
		config.post3x3 config.proto config.rokicki loop.ps \
		mkdvipspapers oneline.tex papersize.level2 papersize.simple \
		prepipe.ps ptmr.ed ptmro.ed rotsample.tex showpage.ps \
		treen.sh treen2.sh
DOCS=		../README.jpatch dvipsk/README \
		dvipsk/dvips.texi dvipsk/dvips.help dvipsk/dvips.cps

pre-patch:
	@${PATCH} -s -d ${WRKSRC} < ${WRKDIR}/dvipsk.patch
	@( cd ${WRKSRC}/dvipsk/contrib ; ${CP} config.rokicki config.ps )

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ] ; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir ; \
	fi

post-install:
	@for i in ${BINARIES} ; do \
	    strip ${PREFIX}/bin/$$i ; \
	done
	@${MKDIR} ${DVIPSDIR}/contrib/volker
	@${MKDIR} ${TEXDIR}/latex209/dvips
	@(\
	  cd ${WRKSRC}/dvipsk/contrib ; \
	  ${INSTALL_DATA} config.ps ${DVIPSDIR}/config.ps ; \
	  for i in ${CONTRIB_FILES} volker/*; do \
	    ${INSTALL_DATA} $$i ${DVIPSDIR}/contrib/$$i ; \
	  done ; \
	  cd ${WRKSRC}/dvipsk/contrib/latex209 ; \
	  for i in *.sty ; do \
	    ${INSTALL_DATA} $$i ${TEXDIR}/latex209/dvips/$$i ; \
	  done \
	)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dvips
	@for i in ${DOCS} ; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/dvips ; \
	done
	@ln -fs ${DVIPSDIR}/contrib ${PREFIX}/share/doc/dvips/contrib
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
