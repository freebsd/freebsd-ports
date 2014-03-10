# Created by: hsu
# $FreeBSD$

PORTNAME=	gcl
PORTVERSION=	2.6.10
PORTREVISION=	1
CATEGORIES=	lang tcl tk
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Common Lisp

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

OPTIONS_DEFINE=	EMACS X11 DOCS
OPTIONS_DEFAULT=EMACS X11
EMACS_DESC=	Install Emacs syntax files

ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake readline
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ansi \
		--enable-machine=${OPSYS} \
		--enable-emacsdir=${PREFIX}/share/emacs/site-lisp/gcl \
		--enable-infodir=${PREFIX}/${INFO_PATH} \
		--disable-dlopen \
		--disable-dynsysbfd \
		--disable-statsysbfd \
		--enable-custreloc
CONFIGURE_ENV=	C_INCLUDE_PATH="${PREFIX}/include" LIBRARY_PATH="${PREFIX}/lib"
MAKEFILE=	makefile
INSTALL_TARGET=	install-command
LATE_INSTALL_ARGS=\
		INSTALL_LIB_DIR="${PREFIX}/lib/${DISTNAME}" \
		prefix="${PREFIX}" \
		BINDIR="${PREFIX}/lib/${DISTNAME}/unixport"
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lreadline -lgmp -lm

INFO=		gcl-si gcl-tk
PORTDOCS=	*
PLIST_FILES=	bin/gcl \
		${FILES_CLCS:S|^|lib/${DISTNAME}/clcs/|} \
		${FILES_CMPNEW:S|^|lib/${DISTNAME}/cmpnew/|} \
		${FILES_H:S|^|lib/${DISTNAME}/h/|} \
		${INFO:S|^|lib/${DISTNAME}/info/|:S|$|.info|} \
		${FILES_LSP:S|^|lib/${DISTNAME}/lsp/|} \
		${PCL_FILES:S|^|lib/${DISTNAME}/pcl/|} \
		${FILES_UNIXPORT:S|^|lib/${DISTNAME}/unixport/|}
PLIST_DIRS=	lib/${DISTNAME}/unixport \
		lib/${DISTNAME}/pcl \
		lib/${DISTNAME}/lsp \
		lib/${DISTNAME}/h \
		lib/${DISTNAME}/info \
		lib/${DISTNAME}/cmpnew \
		lib/${DISTNAME}/clcs \
		lib/${DISTNAME}

FILES_CLCS=	sys-proclaim.lisp
FILES_CMPNEW=	gcl_cmpmain.lsp gcl_cmpopt.lsp gcl_collectfn.lsp \
		gcl_collectfn.o gcl_lfun_list.lsp sys-proclaim.lisp
FILES_H=	cmpinclude.h
FILES_LSP=	gcl_auto_new.lsp gcl_autoload.lsp gcl_export.lsp \
		gcl_gprof.lsp gcl_info.o gcl_profile.lsp \
		sys-proclaim.lisp
FILES_PCL=	sys-proclaim.lisp
FILES_UNIXPORT=	gcl.script init_ansi_gcl.lsp libansi_gcl.a \
		libgclp.a saved_ansi_gcl
FILES_ELISP=	add-default.el ansi-doc.el dbl.el doc-to-texi.el gcl.el \
		man1-to-texi.el smart-complete.el sshell.el
FILES_GCLTK=	decode.tcl gcl.tcl gcltkaux gcltksrv tinfo.o \
		tk-package.lsp tkl.o
FILES_GCLTK_DEMOS=\
		gc-monitor.lisp gc-monitor.o index.lsp \
		mkBasic.lisp mkCanvText.lisp mkEntry.lisp \
		mkEntry2.lisp mkForm.lisp mkHScale.lisp \
		mkItems.lisp mkLabel.lisp mkListbox.lisp \
		mkPlot.lisp mkRadio.lisp mkRuler.lisp \
		mkSearch.lisp mkStyles.lisp mkTextBind.lisp \
		mkVScale.lisp mkdialog.lisp nqthm-stack.lisp \
		showVars.lisp widget.lisp
FILES_XGCL2=	gcl_dwtest.lsp gcl_dwtestcases.lsp sysdef.lisp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMACS}
USE_EMACS=	yes
EMACS_NO_BUILD_DEPENDS=yes
PLIST_FILES+=	${FILES_ELISP:S|^|%%EMACS_SITE_LISPDIR%%/gcl/|}
PLIST_DIRS+=	%%EMACS_SITE_LISPDIR%%/gcl
.endif

.if ${PORT_OPTIONS:MX11}
USES+=		tk
USE_XORG=	x11
CONFIGURE_ARGS+=--enable-tclconfig=${TCL_LIBDIR} \
		--enable-tkconfig=${TK_LIBDIR} \
		--with-x
LDFLAGS+=	-lX11
PLIST_FILES+=	${FILES_GCLTK:S|^|lib/gcl-${PORTVERSION}/gcl-tk/|} \
		${FILES_GCLTK_DEMOS:S|^|lib/gcl-${PORTVERSION}/gcl-tk/demos/|} \
		${FILES_XGCL2:S|^|lib/gcl-${PORTVERSION}/xgcl-2/|}
PLIST_DIRS+=	lib/${DISTNAME}/xgcl-2 \
		lib/${DISTNAME}/gcl-tk/demos \
		lib/${DISTNAME}/gcl-tk
.else
CONFIGURE_ARGS+=--disable-xgcl
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@@CFLAGS@@|${CFLAGS}| ; \
		 s|@@LOCALLIBS@@|${LDFLAGS}|' ${WRKSRC}/h/FreeBSD.defs

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/clcs
.for i in ${FILES_CLCS}
	(cd ${WRKSRC}/clcs && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/clcs)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/cmpnew
.for i in ${FILES_CMPNEW}
	(cd ${WRKSRC}/cmpnew && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/cmpnew)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/info
.for i in ${INFO}
	(cd ${WRKSRC}/info && ${INSTALL_DATA} ${i}.info \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/info)
	(cd ${WRKSRC}/info && ${INSTALL_DATA} ${i}.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH})
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/h
.for i in ${FILES_H}
	(cd ${WRKSRC}/h && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/h)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/lsp
.for i in ${FILES_LSP}
	(cd ${WRKSRC}/lsp && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/lsp)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/pcl
.for i in ${PCL_FILES}
	(cd ${WRKSRC}/pcl && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/pcl)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/unixport
.for i in ${FILES_UNIXPORT}
	(cd ${WRKSRC}/unixport && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/unixport)
.endfor
	@${CHMOD} a+x ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/unixport/saved_ansi_gcl
.if ${PORT_OPTIONS:MEMACS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/gcl
.for i in ${FILES_ELISP}
	(cd ${WRKSRC}/elisp && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/gcl)
.endfor
.endif
.if ${PORT_OPTIONS:MX11}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/gcl-tk
.for i in ${FILES_GCLTK}
	(cd ${WRKSRC}/gcl-tk && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/gcl-tk)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/gcl-tk/demos
.for i in ${FILES_GCLTK_DEMOS}
	(cd ${WRKSRC}/gcl-tk/demos && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/gcl-tk/demos)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/xgcl-2
.for i in ${FILES_XGCL2}
	(cd ${WRKSRC}/xgcl-2 && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}/xgcl-2)
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/xgcl-2 && ${INSTALL_DATA} *.tex \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/dwdoc
	(cd ${WRKSRC}/xgcl-2/dwdoc && ${INSTALL_DATA} *.html \
		${STAGEDIR}${DOCSDIR}/dwdoc)

.include <bsd.port.mk>
