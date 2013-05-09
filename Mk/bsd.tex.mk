# $FreeBSD$
#
# bsd.tex.mk - Common part for TeX related ports
#
TEX_MAINTAINER=	hrs@FreeBSD.org

#
# For ports which depend on TeX:
# USE_TEX=	yes
# Note that teTeX or TeXLive is used based on $TEX_DEFAULT, and full version
# of the packages will be installed as the dependency. 
#
# For full teTeX dependency:
# USE_TEX=	tetex
#
# For full TeXLive dependency:
# USE_TEX=	texlive
#
# The other valid keywords:
#
#  tetex-base:	teTeX base
#  tetex-texmf:	teTeX texmf tree
#
#  web2c:	WEB2C toolchain and TeX engines
#  kpathsea:	kpathsea library
#  ptexenc:	character code conversion library for pTeX
#
#  base:	TeXLive base
#  texmf:	TeXLive texmf tree
#  infra:	tlmgr dependency (Perl modules)
#
#  dvipsk:	dvipsk
#  dvipdfmx:	DVIPDFMx
#  xdvik:	XDvi
#
#  formats:	TeX, LaTeX, PDFTeX, AMSTeX, ConTeXT, CSLaTeX, EplainTeX,
#		METAFONT, MLTeX, PDFTeX, TeXsis
#  aleph:	Aleph
#  jadetex:	JadeTeX
#  luatex:	LuaTeX
#  ptex:	pTeX
#  xetex:	XeTeX
#  xmltex:	XMLTeX
#
#  texhash:	directory search hash regeneration
#  updmap:	font map regeneration
#  fmtutil:	format regeneration
#

# default TeX distribution.  "tetex" or "texlive"
TEX_DEFAULT?=	tetex
#TEX_DEFAULT?=	texlive

# normalize
TEX_DEFAULT:=	${TEX_DEFAULT:L}

.if defined(USE_TEX) && !empty(USE_TEX:M[Yy][Ee][Ss])
USE_TEX:=	${TEX_DEFAULT}
.endif

TEXMFDIR?=	share/texmf
TEXMFDISTDIR?=	share/texmf-dist
TEXMFLOCALDIR?=	share/texmf-local
TEXMFVARDIR?=	share/texmf-var
TEXMFCONFIGDIR?=share/texmf-config
FMTUTIL_CNF?=	${TEXMFCONFIGDIR}/web2c/fmtutil.cnf
TEXHASHDIRS?=	${TEXMFDIR} ${TEXMFDISTDIR} ${TEXMFLOCALDIR} ${TEXMFVARDIR} ${TEXMFCONFIGDIR}

.for V in TEXMFDIR TEXMFDISTDIR TEXMFLOCALDIR TEXMFVARDIR TEXMFCONFIGDIR FMTUTIL_CNF
PLIST_SUB+=	$V="${$V}"
.endfor

CONFLICTS_TEXLIVE= \
	texlive-[0-9]* tex-web2c-[0-9]* \
	tex-kpathsea-[0-9]* tex-xdvik-[0-9]* \
	tex-dvipsk-[0-9]* tex-dvipdfmx-[0-9]*
CONFLICTS_TETEX= \
	teTeX-[0-9]* *-teTeX-[0-9]* \
	teTeX-*-[0-9]* *-teTeX-*-[0-9]* \
	latex2e-[0-9]*

.if !empty(USE_TEX:Mtetex-texmf) || !empty(USE_TEX:Mtetex)
_USE_TETEX_TEXMF=	${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf
CONFLICTS_INSTALL+=	${CONFLICTS_TEXLIVE}
.endif
.if !empty(USE_TEX:Mtetex-base) || !empty(USE_TEX:Mtetex)
_USE_TETEX_BASE=	mktexlsr:${PORTSDIR}/print/teTeX-base
CONFLICTS_INSTALL+=	${CONFLICTS_TEXLIVE}
.endif

.if !empty(USE_TEX:Mweb2c) || !empty(USE_TEX:Mtexlive)
_USE_TEX_WEB2C=		weave:${PORTSDIR}/devel/tex-web2c
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mjadetex) || !empty(USE_TEX:Mtexlive)
_USE_TEX_JADETEX=	jadetex:${PORTSDIR}/print/tex-jadetex
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mxmltex) || !empty(USE_TEX:Mtexlive)
_USE_TEX_XMLTEX=	xmltex:${PORTSDIR}/print/tex-xmltex
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mluatex) || !empty(USE_TEX:Mtexlive)
_USE_TEX_LUATEX=	luatex:${PORTSDIR}/print/tex-luatex
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mxetex) || !empty(USE_TEX:Mtexlive)
_USE_TEX_XETEX=		xetex:${PORTSDIR}/print/tex-xetex
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Maleph) || !empty(USE_TEX:Mtexlive)
_USE_TEX_ALEPH=		aleph:${PORTSDIR}/print/tex-aleph
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mptex) || !empty(USE_TEX:Mtexlive)
_USE_TEX_PTEX=		ptex:${PORTSDIR}/japanese/tex-ptex
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mkpathsea) || !empty(USE_TEX:Mtexlive)
_USE_TEX_KPATHSEA=	kpathsea:${PORTSDIR}/devel/tex-kpathsea
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mptexenc) || !empty(USE_TEX:Mtexlive)
_USE_TEX_PTEXENC=	ptexenc:${PORTSDIR}/print/tex-ptexenc
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mdvipsk) || !empty(USE_TEX:Mtexlive)
_USE_TEX_DVIPSK=	dvips:${PORTSDIR}/print/tex-dvipsk
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mxdvik) || !empty(USE_TEX:Mtexlive)
_USE_TEX_XDVIK=		xdvi:${PORTSDIR}/print/tex-xdvik
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mxdvipdfmx) || !empty(USE_TEX:Mtexlive)
_USE_TEX_DVIPDFMX=	dvipdfmx:${PORTSDIR}/print/tex-dvipdfmx
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mbase) || !empty(USE_TEX:Mtexlive)
_USE_TEXLIVE_BASE=	tlmgr:${PORTSDIR}/print/texlive-base
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mtexmf) || !empty(USE_TEX:Mtexlive)
_USE_TEXLIVE_TEXMF=	${LOCALBASE}/${TEXMFDISTDIR}/README:${PORTSDIR}/print/texlive-texmf
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Mformats) || !empty(USE_TEX:Mtexlive)
_USE_TEX_FORMATS=	${LOCALBASE}/${TEXMFVARDIR}/web2c/tex/tex.fmt:${PORTSDIR}/print/tex-formats
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif
.if !empty(USE_TEX:Minfra) || !empty(USE_TEX:Mtexlive)
_USE_TEXLIVE_INFRA=	${SITE_PERL}/TeXLive/TLConfig.pm:${PORTSDIR}/print/texlive-infra
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.endif

.for D in TETEX_TEXMF TETEX_BASE TEXLIVE_BASE TEX_WEB2C TEXLIVE_TEXMF \
	TEXLIVE_INFRA \
	TEX_FORMATS TEX_ALEPH TEX_JADETEX TEX_XMLTEX TEX_LUATEX \
	TEX_XETEX TEX_PTEX TEX_XDVIK TEX_DVIPSK TEX_DVIPDFMX
RUN_DEPENDS+=	${_USE_${D}}
.endfor
.for D in TETEX_TEXMF TETEX_BASE TEXLIVE_BASE TEX_WEB2C TEXLIVE_TEXMF \
	TEX_FORMATS TEX_ALEPH TEX_JADETEX TEX_XMLTEX TEX_LUATEX \
	TEX_XETEX TEX_PTEX
BUILD_DEPENDS+=	${_USE_${D}}
.endfor
.for D in TEX_KPATHSEA TEX_PTEXENC
LIB_DEPENDS+=	${_USE_${D}}
.endfor

.ORDER: do-texhash do-fmtutil do-updmap

.if !empty(USE_TEX:Mtexhash) || !empty(USE_TEX:Mfmtutil) || !empty(USE_TEX:Mupdmap)
.PHONY:	do-texhash
do-texhash:
	@for D in ${TEXHASHDIRS:S,^,${PREFIX}/,}; do \
		if [ -r $$D/ls-R ]; then ${LOCALBASE}/bin/mktexlsr $$D; fi; \
	done
	@${ECHO_CMD} "@exec for D in ${TEXHASHDIRS:S,^,${PREFIX}/,}; do " \
		"if [ -r \$$D/ls-R ]; then " \
			"${LOCALBASE}/bin/mktexlsr \$$D; " \
		"fi; done" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec for D in ${TEXHASHDIRS:S,^,${PREFIX}/,}; do " \
		"if [ -r \$$D/ls-R ]; then " \
			"${LOCALBASE}/bin/mktexlsr \$$D; " \
		"fi; done" >> ${TMPPLIST}

post-install: do-texhash
.endif

.if !empty(USE_TEX:Mfmtutil)
.PHONY:	do-fmtutil
post-install: do-fmtutil
.for F in ${TEX_FORMATS}
do-fmtutil: do-fmtutil-$F post-install-$F
do-fmtutil-$F:
	@${TEST} -n '${TEX_FORMAT_${F:U}}'
	@${TEST} -r ${LOCALBASE}/${FMTUTIL_CNF}
	@exec < ${LOCALBASE}/${FMTUTIL_CNF} && \
		${RM} ${LOCALBASE}/${FMTUTIL_CNF} && \
		(${GREP} -v "\#$F\$$"; \
			${PRINTF} "%s\t\#$F\n" ${TEX_FORMAT_${F:U}}) \
			> ${LOCALBASE}/${FMTUTIL_CNF}
	@${PRINTF} "%s\t\#$F\n" ${TEX_FORMAT_${F:U}} | \
		while read format dum; do \
		${SETENV} PATH=${PATH}:${LOCALBASE}/bin \
			TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} \
			${LOCALBASE}/bin/fmtutil-sys --byfmt $$format; \
		done
	@${ECHO_CMD} "@exec exec < ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"${RM} ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"(${GREP} -v \"\#$F\$$\"; ${PRINTF} \"%%s\t\#$F\n\" " \
		"${TEX_FORMAT_${F:U}:S,",\\",g}) " \
		"> ${LOCALBASE}/${FMTUTIL_CNF}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec exec < ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"${RM} ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"${GREP} -v \"\#$F\$$\" " \
		"> ${LOCALBASE}/${FMTUTIL_CNF}" >> ${TMPPLIST}
PLIST_FILES+=	${TEX_FORMAT_${F:U}_FILES}
PLIST_DIRSTRY+=	${TEX_FORMAT_${F:U}_DIRS}
.endfor
PLIST_DIRSTRY+=	${TEXMFVARDIR}/web2c \
		${TEXMFVARDIR}
.endif

.if !empty(USE_TEX:Mupdmap)
.PHONY:	do-updmap
do-updmap:
	${SETENV} PATH=${PATH}:${LOCALBASE}/bin \
		TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} \
		${LOCALBASE}/bin/updmap-sys
post-install: do-updmap
	@${ECHO_CMD} "@exec ${SETENV} PATH=${PATH}:${LOCALBASE}/bin " \
		"TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} " \
		"${LOCALBASE}/bin/updmap-sys"  >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${SETENV} PATH=${PATH}:${LOCALBASE}/bin " \
		"TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} " \
		"${LOCALBASE}/bin/updmap-sys"  >> ${TMPPLIST}
.endif

TEX_FORMAT_ALEPH?= \
	"aleph aleph - *aleph.ini" \
	"lamed aleph language.dat *lambda.ini"
TEX_FORMAT_ALEPH_FILES=	\
	${TEXMFVARDIR}/web2c/aleph/aleph.log \
	${TEXMFVARDIR}/web2c/aleph/aleph.fmt \
	${TEXMFVARDIR}/web2c/aleph/lamed.log \
	${TEXMFVARDIR}/web2c/aleph/lamed.fmt \
	bin/lamed
TEX_FORMAT_ALEPH_DIRS=	\
	${TEXMFVARDIR}/web2c/aleph
post-install-aleph:
	${LN} -sf aleph ${PREFIX}/bin/lamed

TEX_FORMAT_AMSTEX?= \
	"amstex pdftex - -translate-file=cp227.tcx *amstex.ini"
TEX_FORMAT_AMSTEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/amstex.log \
	${TEXMFVARDIR}/web2c/pdftex/amstex.fmt \
	bin/amstex
TEX_FORMAT_AMSTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-amstex:
	${LN} -fs pdftex ${PREFIX}/bin/amstex

TEX_FORMAT_CONTEXT?= \
	"cont-en pdftex cont-usr.tex -8bit *cont-en.ini"
# XXX
#	"metafun mpost - metafun.mp"
TEX_FORMAT_CONTEXT_FILES=	\
	${TEXMFVARDIR}/web2c/pdftex/cont-en.log \
	${TEXMFVARDIR}/web2c/pdftex/cont-en.fmt
#	bin/metafun
TEX_FORMAT_CONTEXT_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-context:
	@${DO_NADA}
#	${LN} -sf mpost ${PREFIX}/bin/metafun

TEX_FORMAT_CSLATEX?= \
	"cslatex pdftex - -etex -translate-file=cp227.tcx cslatex.ini" \
	"pdfcslatex pdftex - -etex -translate-file=cp227.tcx cslatex.ini"
TEX_FORMAT_CSLATEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/cslatex.log \
	${TEXMFVARDIR}/web2c/pdftex/cslatex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfcslatex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfcslatex.fmt \
	bin/cslatex \
	bin/pdfcslatex
TEX_FORMAT_CSLATEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-cslatex:
	${LN} -sf pdftex ${PREFIX}/bin/cslatex
	${LN} -sf pdftex ${PREFIX}/bin/pdfcslatex

TEX_FORMAT_EPLAIN?= \
	"eplain pdftex language.dat -translate-file=cp227.tcx *eplain.ini"
TEX_FORMAT_EPLAIN_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/eplain.log \
	${TEXMFVARDIR}/web2c/pdftex/eplain.fmt \
	bin/eplain
TEX_FORMAT_EPLAIN_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-eplain:
	${LN} -sf pdftex ${PREFIX}/bin/eplain

TEX_FORMAT_JADETEX?= \
	"jadetex pdftex language.dat *jadetex.ini" \
	"pdfjadetex pdftex language.dat *pdfjadetex.ini"
TEX_FORMAT_JADETEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/jadetex.log \
	${TEXMFVARDIR}/web2c/pdftex/jadetex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfjadetex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfjadetex.fmt \
	bin/jadetex \
	bin/pdfjadetex
TEX_FORMAT_JADETEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-jadetex:
	${LN} -sf pdftex ${PREFIX}/bin/jadetex
	${LN} -sf pdftex ${PREFIX}/bin/pdfjadetex

TEX_FORMAT_LATEX-BIN?= \
	"latex pdftex language.dat -translate-file=cp227.tcx *latex.ini" \
	"pdflatex pdftex language.dat -translate-file=cp227.tcx *pdflatex.ini"
TEX_FORMAT_LATEX-BIN_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/latex.log \
	${TEXMFVARDIR}/web2c/pdftex/latex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdflatex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdflatex.fmt \
	bin/latex \
	bin/pdflatex
TEX_FORMAT_LATEX-BIN_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-latex-bin:
	${LN} -sf pdftex ${PREFIX}/bin/latex
	${LN} -sf pdftex ${PREFIX}/bin/pdflatex

TEX_FORMAT_LUATEX?= \
	"luatex luatex language.def,language.dat.lua luatex.ini" \
	"dviluatex luatex language.def,language.dat.lua dviluatex.ini" \
	"dvilualatex luatex language.dat,language.dat.lua dvilualatex.ini" \
	"lualatex luatex language.dat,language.dat.lua lualatex.ini"
TEX_FORMAT_LUATEX_FILES= \
	${TEXMFVARDIR}/web2c/luatex/dviluatex.log \
	${TEXMFVARDIR}/web2c/luatex/dviluatex.fmt \
	${TEXMFVARDIR}/web2c/luatex/dvilualatex.log \
	${TEXMFVARDIR}/web2c/luatex/dvilualatex.fmt \
	${TEXMFVARDIR}/web2c/luatex/luatex.log \
	${TEXMFVARDIR}/web2c/luatex/luatex.fmt \
	${TEXMFVARDIR}/web2c/luatex/lualatex.log \
	${TEXMFVARDIR}/web2c/luatex/lualatex.fmt \
	bin/dviluatex \
	bin/dvilualatex \
	bin/lualatex
TEX_FORMAT_LUATEX_DIRS=	\
	${TEXMFVARDIR}/web2c/luatex
post-install-luatex:
	${LN} -sf luatex ${PREFIX}/bin/dviluatex
	${LN} -sf luatex ${PREFIX}/bin/dvilualatex
	${LN} -sf luatex ${PREFIX}/bin/lualatex

TEX_FORMAT_METAFONT?= \
	"mf mf-nowin - -translate-file=cp227.tcx mf.ini"
TEX_FORMAT_METAFONT_FILES= \
	${TEXMFVARDIR}/web2c/metafont/mf.log \
	${TEXMFVARDIR}/web2c/metafont/mf.base
TEX_FORMAT_METAFONT_DIRS= \
	${TEXMFVARDIR}/web2c/metafont
post-install-metafont:
	@${DO_NADA}

TEX_FORMAT_MEX?= \
	"mex pdftex mexconf.tex -translate-file=cp227.tcx *mex.ini" \
	"pdfmex pdftex mexconf.tex -translate-file=cp227.tcx *pdfmex.ini" \
	"utf8mex pdftex mexconf.tex -enc *utf8mex.ini"
TEX_FORMAT_MEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/mex.log \
	${TEXMFVARDIR}/web2c/pdftex/mex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfmex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfmex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/utf8mex.log \
	${TEXMFVARDIR}/web2c/pdftex/utf8mex.fmt \
	bin/mex \
	bin/pdfmex \
	bin/utf8mex
TEX_FORMAT_MEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-mex:
	${LN} -sf pdftex ${PREFIX}/bin/mex
	${LN} -sf pdftex ${PREFIX}/bin/pdfmex
	${LN} -sf pdftex ${PREFIX}/bin/utf8mex

TEX_FORMAT_MLTEX?= \
	"mllatex pdftex language.dat -translate-file=cp227.tcx -mltex mllatex.ini" \
	"mltex pdftex - -translate-file=cp227.tcx -mltex mltex.ini"
TEX_FORMAT_MLTEX_FILES=	\
	${TEXMFVARDIR}/web2c/pdftex/mllatex.log \
	${TEXMFVARDIR}/web2c/pdftex/mllatex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/mltex.log \
	${TEXMFVARDIR}/web2c/pdftex/mltex.fmt \
	bin/mltex \
	bin/mllatex
TEX_FORMAT_MLTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-mltex:
	${LN} -sf pdftex ${PREFIX}/bin/mltex
	${LN} -sf pdftex ${PREFIX}/bin/mllatex

TEX_FORMAT_MPTOPDF?= \
	"mptopdf pdftex - -translate-file=cp227.tcx mptopdf.tex"
TEX_FORMAT_MPTOPDF_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/mptopdf.log \
	${TEXMFVARDIR}/web2c/pdftex/mptopdf.fmt \
	bin/mptopdf
TEX_FORMAT_MPTOPDF_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-mptopdf:
	${LN} -sf pdftex ${PREFIX}/bin/mptopdf

TEX_FORMAT_PDFTEX?= \
	"pdftex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini" \
	"etex pdftex language.def -translate-file=cp227.tcx *etex.ini" \
	"pdfetex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini"
TEX_FORMAT_PDFTEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/pdftex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdftex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/etex.log \
	${TEXMFVARDIR}/web2c/pdftex/etex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfetex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfetex.fmt \
	bin/pdfetex
TEX_FORMAT_PDFTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-pdftex:
	${LN} -sf pdftex ${PREFIX}/bin/pdfetex

TEX_FORMAT_PTEX?= \
	"ptex ptex - ptex.ini" \
	"ptex eptex language.def *eptex.ini" \
	"platex eptex language.dat *platex.ini"
TEX_FORMAT_PTEX_FILES= \
	${TEXMFVARDIR}/web2c/ptex/ptex.log \
	${TEXMFVARDIR}/web2c/ptex/ptex.fmt \
	${TEXMFVARDIR}/web2c/eptex/ptex.log \
	${TEXMFVARDIR}/web2c/eptex/ptex.fmt \
	${TEXMFVARDIR}/web2c/eptex/platex.log \
	${TEXMFVARDIR}/web2c/eptex/platex.fmt \
	bin/platex
TEX_FORMAT_PTEX_DIRS= \
	${TEXMFVARDIR}/web2c/ptex \
	${TEXMFVARDIR}/web2c/eptex
post-install-ptex:
	${LN} -sf eptex ${PREFIX}/bin/platex

TEX_FORMAT_TEX?= \
	"tex tex - tex.ini"
TEX_FORMAT_TEX_FILES= \
	${TEXMFVARDIR}/web2c/tex/tex.log \
	${TEXMFVARDIR}/web2c/tex/tex.fmt
TEX_FORMAT_TEX_DIRS= \
	${TEXMFVARDIR}/web2c/tex
post-install-tex:
	@${DO_NADA}

TEX_FORMAT_TEXSIS?= \
	"texsis pdftex - -translate-file=cp227.tcx texsis.ini"
TEX_FORMAT_TEXSIS_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/texsis.log \
	${TEXMFVARDIR}/web2c/pdftex/texsis.fmt \
	bin/texsis
TEX_FORMAT_TEXSIS_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-texsis:
	${LN} -sf pdftex ${PREFIX}/bin/texsis

TEX_FORMAT_UPTEX?= \
	"uptex uptex - uptex.ini" \
	"euptex euptex language.def *euptex.ini" \
	"uplatex euptex language.dat *uplatex.ini"
TEX_FORMAT_UPTEX_FILES=	\
	${TEXMFVARDIR}/web2c/euptex/euptex.log \
	${TEXMFVARDIR}/web2c/euptex/euptex.fmt \
	${TEXMFVARDIR}/web2c/uptex/uptex.log \
	${TEXMFVARDIR}/web2c/uptex/uptex.fmt \
	${TEXMFVARDIR}/web2c/euptex/uplatex.log \
	${TEXMFVARDIR}/web2c/euptex/uplatex.fmt \
	bin/uplatex
TEX_FORMAT_UPTEX_DIRS=	\
	${TEXMFVARDIR}/web2c/euptex \
	${TEXMFVARDIR}/web2c/uptex
post-install-uptex:
	${LN} -sf euptex ${PREFIX}/bin/uplatex

TEX_FORMAT_XETEX?= \
	"xetex xetex language.def -etex xetex.ini" \
	"xelatex xetex language.dat -etex xelatex.ini" \
	"cont-en xetex cont-usr.tex -8bit *cont-en.ini"
TEX_FORMAT_XETEX_FILES=	\
	${TEXMFVARDIR}/web2c/xetex/xetex.log \
	${TEXMFVARDIR}/web2c/xetex/xetex.fmt \
	${TEXMFVARDIR}/web2c/xetex/xelatex.log \
	${TEXMFVARDIR}/web2c/xetex/xelatex.fmt \
	${TEXMFVARDIR}/web2c/xetex/cont-en.log \
	${TEXMFVARDIR}/web2c/xetex/cont-en.fmt \
	bin/xelatex
TEX_FORMAT_XETEX_DIRS=	\
	${TEXMFVARDIR}/web2c/xetex
post-install-xetex:
	${LN} -sf xetex ${PREFIX}/bin/xelatex

TEX_FORMAT_XMLTEX?= \
	"xmltex pdftex language.dat *xmltex.ini" \
	"pdfxmltex pdftex language.dat *pdfxmltex.ini"
TEX_FORMAT_XMLTEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/xmltex.log \
	${TEXMFVARDIR}/web2c/pdftex/xmltex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfxmltex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfxmltex.fmt \
	bin/xmltex \
	bin/pdfxmltex
TEX_FORMAT_XMLTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-xmltex:
	${LN} -sf pdftex ${PREFIX}/bin/xmltex
	${LN} -sf pdftex ${PREFIX}/bin/pdfxmltex
