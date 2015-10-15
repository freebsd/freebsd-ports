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
# means full TeXLive dependency except for documentation and source.
#
# The other valid keywords
#
#  base:	base part
#  texmf:	texmf tree (except for documentation and source)
#  source:	source 
#  docs:	documentation
#
#  web2c:	WEB2C toolchain and TeX engines
#  kpathsea:	kpathsea library
#  ptexenc:	character code conversion library for pTeX
#  basic:	basic TeX engines including tex and pdftex
#  tlmgr:	tlmgr dependency (Perl modules)
#  texlua:	texlua52 library
#  texluajit:	texluajit library
#  synctex:	synctex library
#  xpdfopen:	pdfopen/pdfclose utility
#
#  dvipsk:	dvipsk
#  dvipdfmx:	DVIPDFMx
#  xdvik:	XDvi
#  gbklatex:	gbklatex
#
#  formats:	TeX, LaTeX, AMSTeX, ConTeXT, CSLaTeX, EplainTeX,
#		CSplainTeX, METAFONT, MLTeX, PDFTeX, TeXsis
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
#  updmap:	font map regeneration
#  fmtutil:	format regeneration
#
# Examples:
# USE_TEX=	latex:build
# USE_TEX=	formats
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

.if !empty(USE_TEX:tu:MTEXLIVE)
IGNORE=		"texlive" must not be defined in USE_TEX 
.endif

_USE_TEX_TEXMF_DEP=	${LOCALBASE}/${TEXMFDISTDIR}/README
_USE_TEX_TEXMF_PORT=	print/${_USE_TEX_TEXMF_PKGNAME}
_USE_TEX_TEXMF_PKGNAME=	texlive-texmf
_USE_TEX_BASE_DEP=	texconfig
_USE_TEX_BASE_PORT=	print/${_USE_TEX_BASE_PKGNAME}
_USE_TEX_BASE_PKGNAME=	texlive-base
_USE_TEX_GBKLATEX_DEP=	gbklatex
_USE_TEX_GBKLATEX_PORT=	${_USE_TEX_BASE_PORT}
_USE_TEX_GBKLATEX_PKGNAME=${_USE_TEX_BASE_PKGNAME}
_USE_TEX_SOURCE_DEP=	${LOCALBASE}/${TEXMFDISTDIR}/source/.keep_me
_USE_TEX_SOURCE_PORT=	print/${_USE_TEX_SOURCE_PKGNAME}
_USE_TEX_SOURCE_PKGNAME=texlive-texmf-source
_USE_TEX_DOCS_DEP=	${LOCALBASE}/${TEXMFDISTDIR}/doc/texlive/texlive-en/README
_USE_TEX_DOCS_PORT=	print/${_USE_TEX_DOCS_PKGNAME}
_USE_TEX_DOCS_PKGNAME=	texlive-docs
_USE_TEX_TLMGR_DEP=	${LOCALBASE}/${TEXMFDISTDIR}/.texlive-tlmgr
_USE_TEX_TLMGR_PORT=	print/${_USE_TEX_TLMGR_PKGNAME}
_USE_TEX_TLMGR_PKGNAME=	texlive-tlmgr
_USE_TEX_DVIPSK_DEP=	dvips
_USE_TEX_DVIPSK_PORT=	print/${_USE_TEX_DVIPSK_PKGNAME}
_USE_TEX_DVIPSK_PKGNAME=tex-dvipsk
_USE_TEX_XDVIK_DEP=	xdvi
_USE_TEX_XDVIK_PORT=	print/${_USE_TEX_XDVIK_PKGNAME}
_USE_TEX_XDVIK_PKGNAME=	tex-xdvik
_USE_TEX_DVIPDFMX_DEP=	dvipdfmx
_USE_TEX_DVIPDFMX_PORT=	print/${_USE_TEX_DVIPDFMX_PKGNAME}
_USE_TEX_DVIPDFMX_PKGNAME=tex-dvipdfmx
_USE_TEX_BASIC_DEP=	tex
_USE_TEX_BASIC_PORT=	print/${_USE_TEX_BASIC_PKGNAME}
_USE_TEX_BASIC_PKGNAME=	tex-basic-engines
.for _L in TEX LATEX PDFTEX
_USE_TEX_${_L}_DEP=	${_USE_TEX_FORMATS_DEP}
_USE_TEX_${_L}_PORT=	${_USE_TEX_FORMATS_PORT}
_USE_TEX_${_L}_PKGNAME=	${_USE_TEX_FORMATS_PKGNAME}
.endfor
_USE_TEX_JADETEX_DEP=	jadetex
_USE_TEX_JADETEX_PORT=	print/${_USE_TEX_JADETEX_PKGNAME}
_USE_TEX_JADETEX_PKGNAME=tex-jadetex
_USE_TEX_XMLTEX_DEP=	xmltex
_USE_TEX_XMLTEX_PORT=	print/${_USE_TEX_XMLTEX_PKGNAME}
_USE_TEX_XMLTEX_PKGNAME=tex-xmltex
_USE_TEX_PTEX_DEP=	ptex
_USE_TEX_PTEX_PORT=	japanese/${_USE_TEX_PTEX_PKGNAME}
_USE_TEX_PTEX_PKGNAME=	tex-ptex
_USE_TEX_WEB2C_DEP=	weave
_USE_TEX_WEB2C_PORT=	devel/${_USE_TEX_WEB2C_PKGNAME}
_USE_TEX_WEB2C_PKGNAME=	tex-web2c
_USE_TEX_KPATHSEA_DEP=	libkpathsea.so
_USE_TEX_KPATHSEA_PORT=	devel/${_USE_TEX_KPATHSEA_PKGNAME}
_USE_TEX_KPATHSEA_PKGNAME=tex-kpathsea
_USE_TEX_PTEXENC_DEP=	libptexenc.so
_USE_TEX_PTEXENC_PORT=	print/${_USE_TEX_PTEXENC_PKGNAME}
_USE_TEX_PTEXENC_PKGNAME=tex-ptexenc
_USE_TEX_TEXLUA_DEP=	libtexlua52.so
_USE_TEX_TEXLUA_PORT=	devel/${_USE_TEX_TEXLUA_PKGNAME}
_USE_TEX_TEXLUA_PKGNAME=tex-libtexlua
_USE_TEX_TEXLUAJIT_DEP=	libtexluajit.so
_USE_TEX_TEXLUAJIT_PORT=	devel/${_USE_TEX_TEXLUAJIT_PKGNAME}
_USE_TEX_TEXLUAJIT_PKGNAME=tex-libtexluajit
_USE_TEX_FORMATS_DEP=	${LOCALBASE}/${TEXMFVARDIR}/web2c/tex/tex.fmt
_USE_TEX_FORMATS_PORT=	print/${_USE_TEX_FORMATS_PKGNAME}
_USE_TEX_FORMATS_PKGNAME=tex-formats
_USE_TEX_SYNCTEX_DEP=	libsynctex.so
_USE_TEX_SYNCTEX_PORT=	devel/${_USE_TEX_SYNCTEX_PKGNAME}
_USE_TEX_SYNCTEX_PKGNAME=tex-synctex
_USE_TEX_XPDFOPEN_DEP=	pdfopen
_USE_TEX_XPDFOPEN_PORT=	print/${_USE_TEX_XPDFOPEN_PKGNAME}
_USE_TEX_XPDFOPEN_PKGNAME=	xpdfopen
_USE_TEX_ALEPH_DEP=	aleph
_USE_TEX_ALEPH_PORT=	print/${_USE_TEX_ALEPH_PKGNAME}
_USE_TEX_ALEPH_PKGNAME=	tex-aleph
_USE_TEX_LUATEX_DEP=	luatex
_USE_TEX_LUATEX_PORT=	print/${_USE_TEX_LUATEX_PKGNAME}
_USE_TEX_LUATEX_PKGNAME=tex-luatex
_USE_TEX_XETEX_DEP=	xetex
_USE_TEX_XETEX_PORT=	print/${_USE_TEX_XETEX_PKGNAME}
_USE_TEX_XETEX_PKGNAME=	tex-xetex

_USE_TEX_FULLLIST=	texmf>=20150523_3 base>=20150521_5 \
		web2c tlmgr:run \
		basic formats aleph xetex jadetex luatex xmltex ptex \
		dvipsk dvipdfmx xdvik xpdfopen:run \
		kpathsea:lib ptexenc:lib texlua:lib texluajit:lib synctex:lib

.if !empty(USE_TEX:tu:MFULL)
USE_TEX:=	${USE_TEX:tu:NFULL} ${_USE_TEX_FULLLIST:tu}
.endif

.for _UU in ${USE_TEX:tu}
_U:=	${_UU}	# ugly but necessary in for loop
_VOP:=
. if !empty(_U:tu:C/[<>=][^\:]*//:C/\:.*$//:MTEXMF) && empty(_U:M*[<>=]*)
_U:=	${_U}>=20150523_3
. endif
. if !empty(_U:tu:C/[<>=][^\:]*//:C/\:.*$//:MBASE) && empty(_U:M*[<>=]*)
_U:=	${_U}>=20150521_5
. endif
. if !empty(_U:tu:C/[<>=][^\:]*//:C/\:.*$//:MKPATHSEA) || \
     !empty(_U:tu:C/[<>=][^\:]*//:C/\:.*$//:MPTEXENC) || \
     !empty(_U:tu:C/[<>=][^\:]*//:C/\:.*$//:MTEXLUA) || \
     !empty(_U:tu:C/[<>=][^\:]*//:C/\:.*$//:MTEXLUAJIT) || \
     !empty(_U:tu:C/[<>=][^\:]*//:C/\:.*$//:MSYNCTEX)
_U:=	${_U}:lib
. endif
. if !empty(_U:M*[<>=]*)
_VOP:=	${_U:C/^[^<>=]*//:C/\:.*$//}
. endif
. if empty(_U:M*\:*)
_C:=	BUILD RUN
. else
_C:=	${_U:C/.*://:S/,/ /g:C/[<>=][^\:]*//g}
. endif
#. warning DEBUG: ${_U}: _VOP=${_VOP}, _C=${_C}
. for _CC in ${_C:tu}
_V:=${_UU:C/[<>=][^\:]*//:C/\:.*$//}
.  if defined(_USE_TEX_${_V}_PORT)
.   if !empty(_VOP)
.    for _T in ${_USE_TEX_${_V}_PKGNAME}${_VOP}:${PORTSDIR}/${_USE_TEX_${_V}_PORT}
TEX_${_CC}_DEPENDS+=	${_T}
.    endfor
.   else
.    for _T in ${_USE_TEX_${_V}_DEP}:${PORTSDIR}/${_USE_TEX_${_V}_PORT}
TEX_${_CC}_DEPENDS+=	${_T}
.    endfor
.   endif
.  endif
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
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/mktexlsr " \
		"${TEXHASHDIRS:S,^,%D/,}" >> ${TMPPLIST}
	@for D in ${TEXHASHDIRS}; do \
		${ECHO_CMD} "@rmtry $$D/ls-R"; \
		${ECHO_CMD} "@dir $$D"; \
	done >> ${TMPPLIST}
. else
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
do-fmtutil: post-install-$F do-fmtutil-$F
do-fmtutil-$F:
	${TEST} -n '${TEX_FORMAT_${F:tu}}'
	${PRINTF} "%s\t#$F\n" ${TEX_FORMAT_${F:tu}} \
	    > ${WRKDIR}/fmtutil.cnf
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFVARDIR}/web2c \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c
	${LN} -f -s ${LOCALBASE}/${TEXMFDISTDIR}/web2c/texmf.cnf \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c/texmf.cnf
	${LOCALBASE}/bin/mktexlsr ${TEXHASHDIRS:S,^,${STAGEDIR}${PREFIX}/,}
	${CAT} ${WRKDIR}/fmtutil.cnf | \
		while read format dum; do \
		${SETENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH}:${LOCALBASE}/bin \
		    TEXMFDIST=${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}:${LOCALBASE}/${TEXMFDISTDIR} \
		    ${LOCALBASE}/bin/fmtutil-sys \
			--byfmt $$format \
			--fmtdir ${STAGEDIR}${PREFIX}/${TEXMFVARDIR}/web2c \
			--cnffile ${WRKDIR}/fmtutil.cnf; \
		done
	# XXX
	#cd ${STAGEDIR}${PREFIX}/${TEXMFVARDIR}/web2c && \
	#	${FIND} . -name "*.log" | ${XARGS} \
	#	    ${REINPLACE_CMD:S/.bak/ ""/} "s,${STAGEDIR},,g"
	${RM} ${TEXHASHDIRS:S,^,${STAGEDIR}${PREFIX}/,:S,$,/ls-R,} \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c/texmf.cnf
	${RMDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c || ${TRUE}
	${RMDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR} || ${TRUE}
_PLIST_FILES+=	${TEX_FORMAT_${F:tu}_FILES}
_PLIST_DIRSTRY+=${TEX_FORMAT_${F:tu}_DIRS}
_PLIST_FILES+=	${TEX_FORMAT_${F:tu}_BIN}
. endfor
post-install-script: do-fmtutil
PLIST_FILES=	${_PLIST_FILES:O:u}
PLIST_DIRSTRY=	${_PLIST_DIRSTRY:O:u} ${TEXMFVARDIR}/web2c
.endif

.if !empty(USE_TEX:Mupdmap)
.PHONY:	do-updmap
do-updmap:
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
	"cont-en pdftex cont-usr.tex -8bit *cont-en.mkii"
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
	"cslatex pdftex - -etex cslatex.ini" \
	"pdfcslatex pdftex - -etex cslatex.ini"
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

TEX_FORMAT_CSPLAIN?= \
	"csplain pdftex - -etex -enc csplain-utf8.ini" \
	"pdfcsplain pdftex - -etex -enc csplain-utf8.ini"
TEX_FORMAT_CSPLAIN_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/csplain.log \
	${TEXMFVARDIR}/web2c/pdftex/csplain.fmt \
	${TEXMFVARDIR}/web2c/pdftex/pdfcsplain.log \
	${TEXMFVARDIR}/web2c/pdftex/pdfcsplain.fmt
TEX_FORMAT_CSPLAIN_BIN= \
	bin/csplain
TEX_FORMAT_CSPLAIN_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-csplain:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/csplain

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
	"lualatex luatex language.dat,language.dat.lua lualatex.ini" \
	"luajittex luajittex language.def,language.dat.lua luatex.ini" \
	"pdfcsplain luatex - -etex csplain.ini" \
	"lualollipop luatex - lualollipop.in"
TEX_FORMAT_LUATEX_FILES= \
	${TEXMFVARDIR}/web2c/luatex/dviluatex.log \
	${TEXMFVARDIR}/web2c/luatex/dviluatex.fmt \
	${TEXMFVARDIR}/web2c/luatex/dvilualatex.log \
	${TEXMFVARDIR}/web2c/luatex/dvilualatex.fmt \
	${TEXMFVARDIR}/web2c/luatex/luatex.log \
	${TEXMFVARDIR}/web2c/luatex/luatex.fmt \
	${TEXMFVARDIR}/web2c/luatex/lualatex.log \
	${TEXMFVARDIR}/web2c/luatex/lualatex.fmt \
	${TEXMFVARDIR}/web2c/luatex/pdfcsplain.log \
	${TEXMFVARDIR}/web2c/luatex/pdfcsplain.fmt \
	${TEXMFVARDIR}/web2c/luajittex/luajittex.log \
	${TEXMFVARDIR}/web2c/luajittex/luajittex.fmt
TEX_FORMAT_LUATEX_BIN= \
	bin/dviluatex \
	bin/dvilualatex \
	bin/luajittex \
	bin/lualatex \
	bin/lualollipop \
	bin/luatex \
	bin/texlua \
	bin/texluac \
	bin/texluajit \
	bin/texluajitc
TEX_FORMAT_LUATEX_DIRS=	\
	${TEXMFVARDIR}/web2c/luatex \
	${TEXMFVARDIR}/web2c/luajittex
post-install-luatex:
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/dviluatex
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/dvilualatex
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/lualatex
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/lualollipop
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/texlua
	${LN} -sf luatex ${STAGEDIR}${PREFIX}/bin/texluac
	${LN} -sf luajittex ${STAGEDIR}${PREFIX}/bin/texluajit
	${LN} -sf luajittex ${STAGEDIR}${PREFIX}/bin/texluajitc

TEX_FORMAT_LOLLIPOP?= \
	"lollipop pdftex - -translate-file=cp227.tcx *lollipop.ini"
TEX_FORMAT_LOLLIPOP_FILES= \
	${TEXMFVARDIR}/web2c/pdftex/lollipop.log \
	${TEXMFVARDIR}/web2c/pdftex/lollipop.fmt
TEX_FORMAT_LOLLIPOP_BIN= \
	bin/lollipop
TEX_FORMAT_LOLLIPOP_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-lollipop-bin:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/lollipop

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
	bin/etex \
	bin/pdfetex
TEX_FORMAT_PDFTEX_DIRS= \
	${TEXMFVARDIR}/web2c/pdftex
post-install-pdftex:
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/pdfetex
	${LN} -sf pdftex ${STAGEDIR}${PREFIX}/bin/etex

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
	bin/eptex \
	bin/ptex \
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
	bin/euptex \
	bin/uptex \
	bin/uplatex
TEX_FORMAT_UPTEX_DIRS=	\
	${TEXMFVARDIR}/web2c/euptex \
	${TEXMFVARDIR}/web2c/uptex
post-install-uptex:
	${LN} -sf euptex ${STAGEDIR}${PREFIX}/bin/uplatex

TEX_FORMAT_XETEX?= \
	"xetex xetex language.def -etex xetex.ini" \
	"xelatex xetex language.dat -etex xelatex.ini" \
	"pdfcsplain xetex - -etex csplain.ini" \
	"cont-en xetex cont-usr.tex -8bit *cont-en.mkii" \
	"xelollipop xetex - -etex xelollipop.ini"
TEX_FORMAT_XETEX_FILES=	\
	${TEXMFVARDIR}/web2c/xetex/cont-en.log \
	${TEXMFVARDIR}/web2c/xetex/cont-en.fmt \
	${TEXMFVARDIR}/web2c/xetex/pdfcsplain.log \
	${TEXMFVARDIR}/web2c/xetex/pdfcsplain.fmt \
	${TEXMFVARDIR}/web2c/xetex/xetex.log \
	${TEXMFVARDIR}/web2c/xetex/xetex.fmt \
	${TEXMFVARDIR}/web2c/xetex/xelatex.log \
	${TEXMFVARDIR}/web2c/xetex/xelatex.fmt \
	${TEXMFVARDIR}/web2c/xetex/xelollipop.log \
	${TEXMFVARDIR}/web2c/xetex/xelollipop.fmt
TEX_FORMAT_XETEX_BIN=	\
	bin/xetex \
	bin/xelatex \
	bin/xelollipop
TEX_FORMAT_XETEX_DIRS=	\
	${TEXMFVARDIR}/web2c/xetex
post-install-xetex:
	${LN} -sf xetex ${STAGEDIR}${PREFIX}/bin/xelatex
	${LN} -sf xetex ${STAGEDIR}${PREFIX}/bin/xelollipop

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
