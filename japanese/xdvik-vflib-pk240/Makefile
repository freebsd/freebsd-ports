# New ports collection makefile for:   xdvik + jp-patch
# Version required:    22.05b
# Date created:        15 Jun 1998
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

DISTNAME=	xdvik-22.05b
PKGNAME=	ja-vfxdvik-22.05b
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/TeX/CTAN/dviware/xdvik/ \
		ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-22/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex218/ \
		ftp://ftp.tex.ac.uk/tex-archive/dviware/xdvik/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} plib-1.4-euc.tar.gz \
		xdvik-22.02-j1.02.patch.gz

#PATCH_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-22/ \
#		${MASTER_SITE_LOCAL}
#PATCHFILES=	xdvik-22.02-j1.02.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	inagaki@tg.rim.or.jp

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

DIST_SUBDIR=	ptex
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=YES
GNU_CONFIGURE=YES
CONFIGURE_ARGS= \
		--enable-a4 --enable-bdpi=300 --enable-shrink=8 \
		--enable-xdviprint=${PREFIX}/libexec/xdviprint
CONFIGURE_ENV= INSTALL="${INSTALL}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"
SCRIPTS_ENV=	MV=${MV} SED=${SED}
VFFONTS=	.:${PREFIX}/share/fonts/makejvf//
TFMFONTS=	.:${PREFIX}/share/fonts/{makejvf:tfm/ptex}//
PKFONTS=	.:${PREFIX}/lib/fonts/pk{118:240:300:360:400:600}//
MAKE_ENV=	XDEFS="-DDEFAULT_VFFONTS='"\"\\\"${VFFONTS}\\\""\"' -DDEFAULT_TFMFONTS='"\"\\\"${TFMFONTS}\\\""\"' -DDEFAULT_PKFONTS='"\"\\\"${PKFONTS}\\\""\"'"
PATCH_STRIP=	-p1
MAN1=xdvi.1

TEXMF=		${PREFIX}/share/texmf
VARTEXFONTS=/var/tmp/texfonts
XDVIDIR=	${TEXMF}/xdvi
PTEXTFMDIR=	${PREFIX}/share/fonts/tfm/ptex
MAKETEX_MODE?=	ljfour
DVIPS?=		dvipsk

PTEXTFM=goth10.tfm goth5.tfm goth6.tfm goth7.tfm goth8.tfm goth9.tfm \
		min10.tfm min5.tfm min6.tfm min7.tfm min8.tfm min9.tfm \
		ngoth10.tfm ngoth5.tfm ngoth6.tfm ngoth7.tfm ngoth8.tfm ngoth9.tfm \
		nmin10.tfm nmin5.tfm nmin6.tfm nmin7.tfm nmin8.tfm nmin9.tfm \
		tgoth10.tfm tgoth5.tfm tgoth6.tfm tgoth7.tfm tgoth8.tfm tgoth9.tfm \
		tmin10.tfm tmin5.tfm tmin6.tfm tmin7.tfm tmin8.tfm tmin9.tfm

DOCS=	FAQ \
		xdvi.icon \
		README \
		README.xdvik-22.x-jp \
		READMEs/ChangeLog.xdvik20a-j1.1 \
		READMEs/ChangeLog.xdvik20c-j1.0 \
		READMEs/HEADERS.DOC \
		READMEs/InternalVars \
		READMEs/README.jp+toc+hal2 \
		READMEs/README.jp-patch \
		READMEs/README.markpage+toc+printdvi \
		READMEs/README.markpage+toc+printdvi+paper \
		READMEs/README.miyu-beta6 \
		READMEs/README.ptex \
		READMEs/README.tasai-ussy \
		READMEs/README.xdvik18f-j1.0.patch \
		READMEs/README.xdvik18f-j1.1p5.patch \
		READMEs/README.xdvik20a-j1.1.patch \
		READMEs/README.xdvik20c-j1.0+hal2+dvisel \
		READMEs/README.xdvik20c-j1.0p1.patch

# ******************
# DVIPS:
#  Please set up [dvipsk¡Ãdvipsk-vflib¡Ãdvi2ps] to DVIPS when I want to
#  change it.
#  Also, please change script $ PREFIX/libexec/xdviprint after installation
#  when the choice other than this wants.
# MAKETEX_MODE:
#  When MetaFont is used the kind of the printer that I use is set up.
#  The default is ljfour.
#  It does not need to change it particularly because it is able to set up it
#  with the option of xdvi.
# ******************

.if ${DVIPS} == dvi2ps
CONFIGURE_ARGS+= --with-dvifilter=dvi2ps
.elif ${DVIPS} == dvipsk-vflib
CONFIGURE_ARGS+= --with-dvifilter=dvips
.elif ${DVIPS} == dvipsk
CONFIGURE_ARGS+= --with-dvifilter=dvips
.else
DVIPS=dvipsk
CONFIGURE_ARGS+= --with-dvifilter=dvips
.endif

#.include <bsd.port.pre.mk>

pre-fetch:
	@( \
	${ECHO} "************************************************************"; \
	${ECHO} "*           japanese/dvipsk is used in default.            *"; \
	${ECHO} "*          Please refer to Makefile about a change.        *"; \
	${ECHO} "************************************************************")

post-extract:
	@${TAR} -C ${WRKDIR}/ -zxf ${DISTDIR}/${DIST_SUBDIR}/plib-1.4-euc.tar.gz \
		texmf/fonts/tfm/ptex

pre-patch:
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/xdvik-22.02-j1.02.patch.gz | ${PATCH} ${PATCH_ARGS} -d ${WRKSRC} 2> /dev/null || exit 0

post-patch:
	@${CAT} ${FILESDIR}/zeit.c.diff | ${PATCH} ${PATCH_ARGS} -d ${WRKSRC}

pre-build:
	@(cd ${WRKSRC} ; find . -name '*.orig' -exec ${RM} -f {} \;)

pre-install:
	@${MKDIR} ${PTEXTFMDIR}
	@for i in ${PTEXTFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/texmf/fonts/tfm/ptex/$$i \
			${PTEXTFMDIR} ; \
	done

do-install:
	@(cd ${WRKSRC}/texk/xdvik ; ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	@$(INSTALL_DATA) $(FILESDIR)/vfontmap $(XDVIDIR)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xdvi
	@for i in ${DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/texk/xdvik/$$i ${PREFIX}/share/doc/xdvi ; \
	done
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
