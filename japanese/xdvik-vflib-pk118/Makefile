# New ports collection makefile for:   xdvik + jp-patch
# Version required:    22.15
# Date created:        15 Jun 1998
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

DISTNAME=	xdvik-22.15
PKGNAME=	ja-vfxdvik-22.15
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.appi.keio.ac.jp/pub/xdvi/ \
		ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-22/ \
		ftp://komadori.planet.sci.kobe-u.ac.jp/pub/xdvi/ \
		ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/xdvi/ \
		ftp://ftp.iij.ad.jp/pub/TeX/CTAN/dviware/xdvik/ \
		ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-22/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/ \
		ftp://ftp.tex.ac.uk/tex-archive/dviware/xdvik/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.appi.keio.ac.jp/pub/xdvi/ \
		ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-22/ \
		ftp://komadori.planet.sci.kobe-u.ac.jp/pub/xdvi/ \
		ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/xdvi/ \
		${MASTER_SITE_LOCAL}
PATCHFILES=	xdvik-22.15-j1.03.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	inagaki@tg.rim.or.jp

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib
RUN_DEPENDS=	makejvf:${PORTSDIR}/japanese/makejvf

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=	xdvik
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= \
		--enable-a4 --enable-bdpi=300 --enable-shrink=8 \
		--enable-xdviprint=${PREFIX}/libexec/xdviprint
CONFIGURE_ENV= INSTALL="${INSTALL}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"
SCRIPTS_ENV=	MV=${MV} SED=${SED}
VFFONTS=	.:${PREFIX}/share/fonts/makejvf/vf//
TFMFONTS=	.:${PREFIX}/share/fonts/makejvf/tfm/ptex//
PKFONTS=	.:${PREFIX}/lib/fonts/pk{118:240:300:360:400:600}//
MAKE_ENV=	XDEFS="-DDEFAULT_VFFONTS='"\"\\\"${VFFONTS}\\\""\"' -DDEFAULT_TFMFONTS='"\"\\\"${TFMFONTS}\\\""\"' -DDEFAULT_PKFONTS='"\"\\\"${PKFONTS}\\\""\"'"
PATCH_STRIP=	-p1
MAN1=		xdvi.1

TEXMF=		${PREFIX}/share/texmf
VARTEXFONTS=	/var/tmp/texfonts
XDVIDIR=	${TEXMF}/xdvi
MAKEJVFDIR=	${PREFIX}/share/fonts/makejvf
MAKETEX_MODE?=	ljfour
DVIPS?=		dvipsk

PTEXTFM=	standard nmin-ngoth jis morisawa
DOCS=		FAQ \
		xdvi.icon \
		CHANGES.xdvik-jp \
		README \
		README.xdvik-jp \
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

pre-build:
	@(cd ${WRKSRC} ; find . -name '*.orig' -exec ${RM} -f {} \;)

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
