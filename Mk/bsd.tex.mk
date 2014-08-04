# $FreeBSD$
#
# bsd.tex.mk - Common part for TeX related ports
#
TEX_MAINTAINER=	hrs@FreeBSD.org

#
# Ports which depend on TeX should use USE_TEX.
#
# USE_TEX=	yes
# imports variables only, and
# USE_TEX=	full
# means TeXLive dependency.
#
# The other valid keywords
#
#  base:	base part
#  texmf:	texmf tree (except for documentation)
#  docs:	documentation
#
#  web2c:	WEB2C toolchain and TeX engines
#  kpathsea:	kpathsea library
#  ptexenc:	character code conversion library for pTeX
#  infra:	tlmgr dependency (Perl modules)
#
#  dvipsk:	dvipsk
#  dvipdfmx:	DVIPDFMx
#  xdvik:	XDvi
#  gbklatex:	gbklatex
#
#  formats:	TeX, LaTeX, PDFTeX, AMSTeX, ConTeXT, CSLaTeX, EplainTeX,
#		METAFONT, MLTeX, PDFTeX, TeXsis[*]
#  tex:		TeX
#  latex:	LaTeX
#  pdftex:	PDFTeX
#  aleph:	Aleph
#  jadetex:	JadeTeX
#  luatex:	LuaTeX
#  ptex:	pTeX
#  xetex:	XeTeX
#  xmltex:	XMLTeX
#
#  texhash:	directory search hash regeneration
#  updmap:	font map regeneration[*]
#  fmtutil:	format regeneration[*]
#
# Examples:
# USE_TEX=	latex:build
# USE_TEX=	formats texlive
# USE_TEX=	latex:build dvipsk:build

# default TeX distribution.  "texlive"
TEX_DEFAULT?=	texlive

.if ${TEX_DEFAULT} != texlive
IGNORE=		Only 'texlive' is supported as value for TEX_DEFAULT
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

# override the user configuration
.if !empty(USE_TEX:tu:MTEXLIVE)
TEX_DEFAULT=	texlive
.endif

.if !empty(TEX_DEFAULT:tu:MTETEX)
CONFLICTS_INSTALL+=	${CONFLICTS_TEXLIVE}
.elif !empty(TEX_DEFAULT:tu:MTEXLIVE)
CONFLICTS_INSTALL+=	${CONFLICTS_TETEX}
.else
.error malformed TEX_DEFAULT: ${TEX_DEFAULT}
.endif

_TEX_LABEL:=	${TEX_DEFAULT:tu:S/TEXLIVE/TEX/}

_USE_TEX_TEXMF=		${LOCALBASE}/${TEXMFDISTDIR}/README:${PORTSDIR}/print/texlive-texmf

_USE_TEX_BASE=		tlmgr:${PORTSDIR}/print/texlive-base

_USE_TEX_GBKLATEX=	gbklatex:${PORTSDIR}/print/texlive-base

_USE_TEX_DOCS=		${LOCALBASE}/${TEXMFDIR}/doc/texlive/texlive-en/README:${PORTSDIR}/print/texlive-docs

_USE_TEX_INFRA=		texlive-infra>=0:${PORTSDIR}/print/texlive-infra

_USE_TEX_DVIPSK=	dvips:${PORTSDIR}/print/tex-dvipsk

_USE_TEX_XDVIK=		xdvi:${PORTSDIR}/print/tex-xdvik

_USE_TEX_DVIPDFMX=	dvipdfmx:${PORTSDIR}/print/tex-dvipdfmx

_USE_TEX_TEX=		${_USE_TEX_FORMATS}

_USE_TEX_LATEX=		${_USE_TEX_FORMATS}

_USE_TEX_PDFTEX=	${_USE_TEX_FORMATS}

_USE_TEX_JADETEX=	jadetex:${PORTSDIR}/print/tex-jadetex

_USE_TEX_XMLTEX=	xmltex:${PORTSDIR}/print/tex-xmltex

_USE_TEX_PTEX=		ptex:${PORTSDIR}/japanese/tex-ptex

_USE_TEX_WEB2C=		weave:${PORTSDIR}/devel/tex-web2c
_USE_TEX_KPATHSEA=	libkpathsea.so:${PORTSDIR}/devel/tex-kpathsea
_USE_TEX_PTEXENC=	libptexenc.so:${PORTSDIR}/print/tex-ptexenc
_USE_TEX_FORMATS=	${LOCALBASE}/${TEXMFVARDIR}/web2c/tex/tex.fmt:${PORTSDIR}/print/tex-formats
_USE_TEX_ALEPH=		aleph:${PORTSDIR}/print/tex-aleph
_USE_TEX_LUATEX=	luatex:${PORTSDIR}/print/tex-luatex
_USE_TEX_XETEX=		xetex:${PORTSDIR}/print/tex-xetex

_USE_TEX_FULL=	texmf base web2c infra \
		formats aleph xetex jadetex luatex xmltex ptex \
		dvipsk dvipdfmx xdvik \
		kpathsea:lib ptexenc:lib

.if !empty(USE_TEX:tu:MFULL)
USE_TEX:=	${_USE_${_TEX_LABEL}_FULL}
.endif

.for _UU in ${USE_TEX:tu}
_U:=	${_UU}	# ugly but necessary in for loop
. if !empty(_U:tu:MKPATHSEA) || !empty(_U:tu:MPTEXENC)
_U:=	${_U}:lib
. endif
. if empty(_U:M*\:*)
_C:=	BUILD RUN
. else
_C:=	${_U:C/.*://}
. endif
. for _CC in ${_C:tu}
TEX_${_CC}_DEPENDS+=${_USE_${_TEX_LABEL}_${_UU:C/:.*$//}}
. endfor
.endfor

.for _C in EXTRACT BUILD LIB RUN
${_C}_DEPENDS+=	${TEX_${_C}_DEPENDS:O:u}
.endfor

.ORDER: do-texhash do-fmtutil do-updmap

.if !empty(USE_TEX:Mtexhash) || \
    !empty(USE_TEX:Mtexhash-bootstrap) || \
    !empty(USE_TEX:Mfmtutil) || \
    !empty(USE_TEX:Mupdmap)
.PHONY:	do-texhash
do-texhash:
. if !empty(USE_TEX:Mtexhash-bootstrap)
.if defined(NO_STAGE)
	@${LOCALBASE}/bin/mktexlsr ${TEXHASHDIRS:S,^,${PREFIX}/,}
.endif
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/mktexlsr " \
		"${TEXHASHDIRS:S,^,%D/,}" >> ${TMPPLIST}
	@for D in ${TEXHASHDIRS}; do \
		${ECHO_CMD} "@unexec ${RM} -f %D/$$D/ls-R"; \
		${ECHO_CMD} "@unexec ${RMDIR} %D/$$D 2> /dev/null || ${TRUE}"; \
	done >> ${TMPPLIST}
. else
.if defined(NO_STAGE)
	@for D in ${TEXHASHDIRS:S,^,${PREFIX}/,}; do \
		if [ -r $$D/ls-R ]; then ${LOCALBASE}/bin/mktexlsr $$D; fi; \
	done
.endif
	@${ECHO_CMD} "@exec for D in ${TEXHASHDIRS:S,^,${PREFIX}/,}; do " \
		"if [ -r \$$D/ls-R ]; then " \
			"${LOCALBASE}/bin/mktexlsr \$$D; " \
		"fi; done" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec for D in ${TEXHASHDIRS:S,^,${PREFIX}/,}; do " \
		"if [ -r \$$D/ls-R ]; then " \
			"${LOCALBASE}/bin/mktexlsr \$$D; " \
		"fi; done" >> ${TMPPLIST}
. endif

post-install-script: do-texhash
.endif

.if !empty(USE_TEX:Mfmtutil)
.PHONY:	do-fmtutil
. for F in ${TEX_FORMATS}
do-fmtutil: do-fmtutil-$F post-install-$F
do-fmtutil-$F:
.if !defined(NO_STAGE)
	@${ECHO_CMD} "@fmtutil ${TEX_FORMAT_${F:tu}_FILES:S@^@${LOCALBASE}/@}" >> ${TMPPLIST}
.endif
.if defined(NO_STAGE)
	@${TEST} -n '${TEX_FORMAT_${F:tu}}'
	@${TEST} -r ${LOCALBASE}/${FMTUTIL_CNF}
	@exec < ${LOCALBASE}/${FMTUTIL_CNF} && \
		${RM} ${LOCALBASE}/${FMTUTIL_CNF} && \
		(${GREP} -v "\#$F\$$"; \
			${PRINTF} "%s\t\#$F\n" ${TEX_FORMAT_${F:tu}}) \
			> ${LOCALBASE}/${FMTUTIL_CNF}
	@${PRINTF} "%s\t\#$F\n" ${TEX_FORMAT_${F:tu}} | \
		while read format dum; do \
		${SETENV} PATH=${PATH}:${LOCALBASE}/bin \
			TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} \
			${LOCALBASE}/bin/fmtutil-sys --byfmt $$format; \
		done
	@${LOCALBASE}/bin/mktexlsr ${TEXMFVARDIR:S,^,${PREFIX}/,}
.endif
	@${ECHO_CMD} "@exec exec < ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"${RM} ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"(${GREP} -v \"\#$F\$$\"; ${PRINTF} \"%%s\t\#$F\n\" " \
		"${TEX_FORMAT_${F:tu}:S,",\\",g}) " \
		"> ${LOCALBASE}/${FMTUTIL_CNF}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec exec < ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"${RM} ${LOCALBASE}/${FMTUTIL_CNF} && " \
		"${GREP} -v \"\#$F\$$\" " \
		"> ${LOCALBASE}/${FMTUTIL_CNF}" >> ${TMPPLIST}
.if defined(NO_STAGE)
_PLIST_FILES+=	${TEX_FORMAT_${F:tu}_FILES}
_PLIST_DIRSTRY+=${TEX_FORMAT_${F:tu}_DIRS}
.endif
_PLIST_FILES+=	${TEX_FORMAT_${F:tu}_BIN}
. endfor
post-install-script: do-fmtutil

PLIST_FILES=	${_PLIST_FILES:O:u}
PLIST_DIRSTRY=	${_PLIST_DIRSTRY:O:u} 
.if defined(NO_STAGE)
PLIST_DIRSTRY=	${TEXMFVARDIR}/web2c \
		${TEXMFVARDIR}
.endif
.endif

.if !empty(USE_TEX:Mupdmap)
.PHONY:	do-updmap
do-updmap:
.if defined(NO_STAGE)
	${SETENV} PATH=${PATH}:${LOCALBASE}/bin \
		TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} \
		${LOCALBASE}/bin/updmap-sys
.endif
	@${ECHO_CMD} "@exec ${SETENV} PATH=${PATH}:${LOCALBASE}/bin " \
		"TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} " \
		"${LOCALBASE}/bin/updmap-sys"  >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${SETENV} PATH=${PATH}:${LOCALBASE}/bin " \
		"TEXMFMAIN=${LOCALBASE}/${TEXMFDIR} " \
		"${LOCALBASE}/bin/updmap-sys"  >> ${TMPPLIST}

post-install-script: do-updmap
.endif

TEX_FORMAT_ALEPH?= \
	"aleph aleph - *aleph.ini" \
	"lamed aleph language.dat *lambda.ini"
TEX_FORMAT_ALEPH_FILES=	\
	${TEXMFVARDIR}/web2c/aleph/aleph.log \
	${TEXMFVARDIR}/web2c/aleph/aleph.fmt \
	${TEXMFVARDIR}/web2c/aleph/lamed.log \
	${TEXMFVARDIR}/web2c/aleph/lamed.fmt
TEX_FORMAT_ALEPH_BIN=	\
	bin/lamed
TEX_FORMAT_ALEPH_DIRS=	\
	${TEXMFVARDIR}/web2c/aleph
post-install-aleph:
	${LN} -sf aleph ${STAGEDIR}${PREFIX}/bin/lamed

TEX_FORMAT_AMSTEX?= \
	"amstex pdftex - -translate-file=cp227.tcx *amstex.ini"
TEX_FORMAT_AMSTEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/amstex.log \
	${TEXMFVARDIR}/web2c/pdftex/amstex.fmt
TEX_FORMAT_AMSTEX_BIN= \
	bin/amstex
TEX_FORMAT_AMSTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-amstex:
	${LN} -fs pdftex ${STAGEDIR}${PREFIX}/bin/amstex

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
	${TEXMFVARDIR}/web2c/pdftex/pdfcslatex.fmt
TEX_FORMAT_CSLATEX_BIN= \
	bin/cslatex \
	bin/pdfcslatex
TEX_FORMAT_CSLATEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-cslatex:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/cslatex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/pdfcslatex

TEX_FORMAT_EPLAIN?= \
	"eplain pdftex language.dat -translate-file=cp227.tcx *eplain.ini"
TEX_FORMAT_EPLAIN_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/eplain.log \
	${TEXMFVARDIR}/web2c/pdftex/eplain.fmt
TEX_FORMAT_EPLAIN_BIN= \
	bin/eplain
TEX_FORMAT_EPLAIN_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-eplain:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/eplain

TEX_FORMAT_JADETEX?= \
	"jadetex pdftex language.dat *jadetex.ini" \
	"pdfjadetex pdftex language.dat *pdfjadetex.ini"
TEX_FORMAT_JADETEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/jadetex.log \
	${TEXMFVARDIR}/web2c/pdftex/jadetex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfjadetex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfjadetex.fmt
TEX_FORMAT_JADETEX_BIN= \
	bin/jadetex \
	bin/pdfjadetex
TEX_FORMAT_JADETEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-jadetex:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/jadetex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/pdfjadetex

TEX_FORMAT_LATEX-BIN?= \
	"latex pdftex language.dat -translate-file=cp227.tcx *latex.ini" \
	"pdflatex pdftex language.dat -translate-file=cp227.tcx *pdflatex.ini"
TEX_FORMAT_LATEX-BIN_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/latex.log \
	${TEXMFVARDIR}/web2c/pdftex/latex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdflatex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdflatex.fmt
TEX_FORMAT_LATEX-BIN_BIN= \
	bin/latex \
	bin/pdflatex
TEX_FORMAT_LATEX-BIN_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-latex-bin:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/latex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/pdflatex

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
	${TEXMFVARDIR}/web2c/luatex/lualatex.fmt
TEX_FORMAT_LUATEX_BIN= \
	bin/dviluatex \
	bin/dvilualatex \
	bin/lualatex
TEX_FORMAT_LUATEX_DIRS=	\
	${TEXMFVARDIR}/web2c/luatex
post-install-luatex:
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/dviluatex
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/dvilualatex
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/lualatex

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
	${TEXMFVARDIR}/web2c/pdftex/utf8mex.fmt
TEX_FORMAT_MEX_BIN= \
	bin/mex \
	bin/pdfmex \
	bin/utf8mex
TEX_FORMAT_MEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-mex:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/mex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/pdfmex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/utf8mex

TEX_FORMAT_MLTEX?= \
	"mllatex pdftex language.dat -translate-file=cp227.tcx -mltex mllatex.ini" \
	"mltex pdftex - -translate-file=cp227.tcx -mltex mltex.ini"
TEX_FORMAT_MLTEX_FILES=	\
	${TEXMFVARDIR}/web2c/pdftex/mllatex.log \
	${TEXMFVARDIR}/web2c/pdftex/mllatex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/mltex.log \
	${TEXMFVARDIR}/web2c/pdftex/mltex.fmt
TEX_FORMAT_MLTEX_BIN= \
	bin/mltex \
	bin/mllatex
TEX_FORMAT_MLTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-mltex:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/mltex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/mllatex

TEX_FORMAT_MPTOPDF?= \
	"mptopdf pdftex - -translate-file=cp227.tcx mptopdf.tex"
TEX_FORMAT_MPTOPDF_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/mptopdf.log \
	${TEXMFVARDIR}/web2c/pdftex/mptopdf.fmt
TEX_FORMAT_MPTOPDF_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-mptopdf:
	@${DO_NADA}

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
	${TEXMFVARDIR}/web2c/pdftex/pdfetex.fmt
TEX_FORMAT_PDFTEX_BIN= \
	bin/pdfetex
TEX_FORMAT_PDFTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-pdftex:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/pdfetex

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
	${TEXMFVARDIR}/web2c/eptex/platex.fmt
TEX_FORMAT_PTEX_BIN= \
	bin/platex
TEX_FORMAT_PTEX_DIRS= \
	${TEXMFVARDIR}/web2c/ptex \
	${TEXMFVARDIR}/web2c/eptex
post-install-ptex:
	${LN} -sf eptex ${STAGEDIR}${PREFIX}/bin/platex

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
	${TEXMFVARDIR}/web2c/pdftex/texsis.fmt
TEX_FORMAT_TEXSIS_BIN= \
	bin/texsis
TEX_FORMAT_TEXSIS_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-texsis:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/texsis

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
	${TEXMFVARDIR}/web2c/euptex/uplatex.fmt
TEX_FORMAT_UPTEX_BIN= \
	bin/uplatex
TEX_FORMAT_UPTEX_DIRS=	\
	${TEXMFVARDIR}/web2c/euptex \
	${TEXMFVARDIR}/web2c/uptex
post-install-uptex:
	${LN} -sf euptex ${STAGEDIR}${PREFIX}/bin/uplatex

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
	${TEXMFVARDIR}/web2c/xetex/cont-en.fmt
TEX_FORMAT_XETEX_BIN=	\
	bin/xelatex
TEX_FORMAT_XETEX_DIRS=	\
	${TEXMFVARDIR}/web2c/xetex
post-install-xetex:
	${LN} -sf xetex ${STAGEDIR}${PREFIX}/bin/xelatex

TEX_FORMAT_XMLTEX?= \
	"xmltex pdftex language.dat *xmltex.ini" \
	"pdfxmltex pdftex language.dat *pdfxmltex.ini"
TEX_FORMAT_XMLTEX_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/xmltex.log \
	${TEXMFVARDIR}/web2c/pdftex/xmltex.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfxmltex.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfxmltex.fmt
TEX_FORMAT_XMLTEX_BIN= \
	bin/xmltex \
	bin/pdfxmltex
TEX_FORMAT_XMLTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-xmltex:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/xmltex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/pdfxmltex
