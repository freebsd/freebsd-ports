# New ports collection makefile for:   xdvik + jp-patch
# Date created:        15 Jun 1998
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	xdvik-vflib
PORTVERSION=	22.40w.1.17
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xdvi
DISTNAME=	xdvik-22.40w

PATCH_SITES=	http://www.nn.iij4u.or.jp/~tutimura/tex/
PATCHFILES=	xdvik-22.40w-j1.17.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	inagaki@tg.rim.or.jp
COMMENT=	DVI Previewer(kpathsearch) for X. + jp-patch

LIB_DEPENDS=	VFlib2:${PORTSDIR}/japanese/vflib \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

DIST_SUBDIR=	xdvik
USE_XLIB=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-a4 --enable-shrink=${SHRINK} \
		--with-dvifilter=${DVIPS} \
		--enable-xdviprint=${PREFIX}/libexec/xdviprint \
		--enable-smallpanel --enable-zoombutton \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--enable-vikey --disable-multiplatform
CONFIGURE_ENV=	INSTALL="${INSTALL}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}" \
		XDEFS='-DMFMODE=\"${MF_MODE}\"'
SCRIPTS_ENV=	MV=${MV} SED=${SED}
#MAKE_ENV=	'XDEFS=${XDEFS}'
PATCH_STRIP=	-p1
MAN1=		xdvi.1 xdvizilla.1 t1mapper.1

LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}
TEXMF=		${PREFIX}/share/texmf
#VARTEXFONTS=	/var/tmp/texfonts
XDVIDIR=	${TEXMF}/xdvi
APPDEFAULTSDIR?=	lib/X11/app-defaults

PLIST_SUB+=	APPDEFAULTSDIR=${APPDEFAULTSDIR}

#VFFONTS=	.:${MAKEJVFDIR}/vf//
#XDEFS+=		-DDEFAULT_VFFONTS=\"\\\"${VFFONTS}\\\"\"
#TFMFONTS=	.:${MAKEJVFDIR}/tfm/ptex//
#XDEFS+=		-DDEFAULT_TFMFONTS=\"\\\"${TFMFONTS}\\\"\"
#PKFONTS=	.:${PREFIX}/lib/fonts/pk{118:240:300:360:400:600}//
#XDEFS+=		-DDEFAULT_PKFONTS=\"\\\"${PKFONTS}\\\"\"

DOCS=		FAQ xdvi.icon CHANGES.xdvik-jp \
		README.xdvik-jp \
		README.src-specials \
		README.t1fonts \
		README.t1mapper \
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
		READMEs/README.xdvik20c-j1.0p1.patch \
		READMEs/README.vf2ft \
		READMEs/README.xdvik-22.15-j1.04.patch

# ******************
# USEPK_MODE:
#  Mode name of Metafont to give to print/pkfonts* is set.
#  It is care-and-attention to the other program how MetaFont wants to
#  be executed that do not use modeless. Kpathsea always searches
#  modeless because even if you specify any kind of mode.
# MAKETEX_MODE:
#  It is mode name of default at executing MetaFont. The default is ljfour.
#  This needs not to be changed. It can be changed with an option or resource.
# DVIPS:
#  Specification of `dvi -> ps' conversion program to use.
#  You can set following one: dvips, dvipsk-vflib, dvi2ps.
#  Other way... After installation if you change script
#  ${PREFIX}/libexec/xdviprint, any kind of program can be used.
# ******************
FONTTYPE?=	metafont
USEPK_MODE?=	cx
MAKETEX_MODE?=	cx
SHRINK?=	6
BDPI?=		300
DVIPS?=		dvips

.if ${FONTTYPE} == metafont
RUN_DEPENDS+=	mktexpk:${PORTSDIR}/japanese/ptex-base
MF_MODE=	${MAKETEX_MODE}
.else
MF_MODE=	${USEPK_MODE}
CONFIGURE_ARGS+=--without-mktexpk-default
.if ${FONTTYPE} == pkall
PKGNAMESUFFIX=	-${FONTTYPE}
.else
PKGNAMESUFFIX=	-pk${BDPI}
.endif
.endif

.BEGIN:
.if ${FONTTYPE} != metafont && \
	${FONTTYPE} != pkfont && ${FONTTYPE} != pkall
	@${ECHO} "Error: invalid value for FONTTYPE: \"${FONTTYPE}\""
	@${ECHO} "Possible values are: metafont, pkall and pkfont."
	@${FALSE}
.endif
.if ${BDPI} != 118 && ${BDPI} != 240 && \
	${BDPI} != 300 && ${BDPI} != 360 && \
	${BDPI} != 400  && ${BDPI} != 600
	@${ECHO} "Error: invalid value for BDPI: \"${BDPI}\""
	@${ECHO} "Possible values are: all, 118, 240, 300, 360, 400 and 600."
	@${FALSE}
.endif
.if ${DVIPS} != dvi2ps && ${DVIPS} != dvips
	@${ECHO} "Error: invalid value for DVIPS: \"${DVIPS}\""
	@${ECHO} "Possible values are: dvi2ps and dvips."
	@${FALSE}
.endif

.include <bsd.port.pre.mk>

pre-fetch:
	@( \
	${ECHO} "**************************************************************"; \
	${ECHO} "*            japanese/dvipsk is used in default.             *"; \
	${ECHO} "*          Please refer to Makefile about a change.          *"; \
	${ECHO} "*           or, after installation, please change            *"; \
	${ECHO} "*                ${PREFIX}/libexec/xdviprint.                *"; \
	${ECHO} "**************************************************************")

pre-build:
	@(cd ${WRKSRC} ; ${FIND} . -name '*.orig' -exec ${RM} -f {} \;)

do-install:
	@(cd ${WRKSRC}/texk/xdvik ; ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	@${INSTALL_DATA} ${FILESDIR}/vfontmap ${XDVIDIR}
	@${INSTALL_DATA} ${WRKSRC}/texk/xdvik/texmf/XDvi ${X11BASE}/${APPDEFAULTSDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/texk/xdvik/$$i ${DOCSDIR}; \
	done
.endif
	@[ -x ${PREFIX}/bin/mktexlsr ] && ${PREFIX}/bin/mktexlsr ${PREFIX}/share/texmf

.include <bsd.port.post.mk>
