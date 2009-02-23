# New ports collection makefile for:	sml_tk
# Date created:		2008-01-13
# Whom:			Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	sml_tk
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.informatik.uni-bremen.de/~cxl/sml_tk/
DISTNAME=	smltk

MAINTAINER=	timbob@bigpond.com
COMMENT=	Typed and abstract Standard ML interface to Tcl/Tk

USE_TK_WRAPPER=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	SMLNJDEVEL	"Build with and stabilize for SML/NJ." on \
		POLYML		"Build and save state for Poly/ML"     on

ALL_TARGET=	smltk
SUB_FILES=	sml_tk.1
MAN1=		sml_tk.1

.include <bsd.port.pre.mk>

.if defined(WITH_SMLNJDEVEL)
BUILD_DEPENDS+=	smlnj-devel>=65:${PORTSDIR}/lang/sml-nj-devel
.endif
.if defined(WITH_POLYML)
BUILD_DEPENDS+=	poly:${PORTSDIR}/lang/polyml
.endif

MAKE_ENV+=	WRKSRC=${WRKSRC} WISH=${WISH}

.if defined(WITH_SMLNJDEVEL)
MAKE_ENV+=	STABILIZE=yes SMLNJDEVEL=yes
PLIST_SUB+=	STABLE="" SMLNJBIN=""
.else
MAKE_ENV+=	STABILIZE=no SMLNJDEVEL=no
PLIST_SUB+=	STABLE="@comment " SMLNJBIN="@comment "
.endif

.if defined(WITH_POLYML)
MAKE_ENV+=	POLYML=yes
PLIST_SUB+=	POLYSTATE=""
.else
MAKE_ENV+=	POLYML=no
PLIST_SUB+=	POLYSTATE="@comment "
.endif

post-extract:
	@${CP} ${WRKSRC}/src/toolkit/filer.sml ${WRKSRC}/src/toolkit/njfiler.sml
	@${SED} -e 's|%%WISH%%|${WISH}|'       \
	       -e 's|%%SMLTKLIB%%|${DATADIR}|' \
	       ${FILESDIR}/src-sys_conf.sml > ${WRKSRC}/src/sys_conf.sml
	@${CP} ${FILESDIR}/src-mlton.sml ${WRKSRC}/src/mlton.sml
	@${CP} ${FILESDIR}/src-sml_tk.mlb ${WRKSRC}/src/sml_tk.mlb
	@${CP} ${FILESDIR}/src-toolkit-toolkit.mlb ${WRKSRC}/src/toolkit/toolkit.mlb
	@${CP} ${FILESDIR}/src-toolkit-regExp-regexp.mlb \
	       ${WRKSRC}/src/toolkit/regExp/regexp.mlb
	@${CP} ${FILESDIR}/src-std_lib-std_lib.mlb ${WRKSRC}/src/std_lib/std_lib.mlb
	@${CHMOD} 0644 ${WRKSRC}/lib/images/info.gif

post-build:
.if defined(WITH_SMLNJDEVEL)
	SMLNJ_DEVEL=yes heap2exec \
		${WRKSRC}/bin/sml_tk.heap.x86-bsd ${WRKSRC}/bin/sml_tk
.endif

do-install:
	@(cd ${WRKSRC}/lib; for d in `find . -type d`; do            \
	    ${MKDIR} ${DATADIR}/$$d;                                 \
	 done)
	@(cd ${WRKSRC}/lib; for f in `find . -type f -perm 0755`; do \
	    ${INSTALL_SCRIPT} $$f ${DATADIR}/$$f;                    \
	 done)
	@(cd ${WRKSRC}/lib; for f in `find . -type f -perm 0644 `; do \
	    ${INSTALL_DATA} $$f ${DATADIR}/$$f;                       \
	 done)
	@(cd ${WRKSRC}/src; \
	 for d in `find . -name .cm \! -prune -o \( -type d \! -name .cm \)`;\
	 do ${MKDIR} ${PREFIX}/lib/${PORTNAME}/$$d;                          \
	 done)
	@(cd ${WRKSRC}/src; \
	 for f in `find . -name .cm \! -prune -o -type f \! \( -regex '.*\.orig' -o -name .cvsignore \)`;\
	 do ${INSTALL_DATA} $$f ${PREFIX}/lib/${PORTNAME}/$$f;                \
	 done)
	@${LN} -s ${PREFIX}/lib/${PORTNAME}/smltk.cm \
		  ${PREFIX}/lib/${PORTNAME}/sml_tk.cm
.if defined(WITH_SMLNJDEVEL)
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/sml_tk ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/.cm
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/.cm/x86-unix
	@${INSTALL_DATA} ${WRKSRC}/src/.cm/x86-unix/sources.cm \
			${PREFIX}/lib/${PORTNAME}/.cm/x86-unix/sources.cm
	@${LN} -s ${PREFIX}/lib/${PORTNAME}/.cm/x86-unix/sources.cm \
	          ${PREFIX}/lib/${PORTNAME}/.cm/x86-unix/sml_tk.cm
.endif
.if defined(WITH_POLYML)
	@${INSTALL_DATA} ${WRKSRC}/bin/sml_tk.poly \
			${PREFIX}/lib/${PORTNAME}/sml_tk.poly
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/doc/manual.html ${DOCSDIR}/manual.html
	@${MKDIR} ${DOCSDIR}/images
	@for f in `ls ${WRKSRC}/doc/images/`; do                               \
		${INSTALL_DATA} ${WRKSRC}/doc/images/$$f ${DOCSDIR}/images/$$f;\
	done
.endif
	@${INSTALL_MAN} ${WRKDIR}/sml_tk.1 ${MANPREFIX}/man/man1/sml_tk.1

.include <bsd.port.post.mk>
