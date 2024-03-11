PORTNAME=	lablgl
PORTVERSION=	1.05
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/lsl/dist/ \
		https://forge.ocamlcore.org/frs/download.php/1254/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL interface for Objective Caml
WWW=		https://forge.ocamlcore.org/projects/lablgl/

LICENSE=	BSD3CLAUSE

CONFLICTS=	ocaml-nox11

USES=		gl gmake tk xorg
USE_XORG=	x11 xext xmu
USE_GL=		gl glu glut
USE_OCAML=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_TK=	yes
OCAML_LDLIBS=	${OCAML_SITELIBDIR}/lablGL

ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/lablgl
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/lablgl

PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

OPTIONS_DEFINE=	THREADS DOCS
OPTIONS_DEFAULT=	THREADS

THREADS_DESC=	Threaded Tcl/Tk (must match lang/ocaml)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREADS}
THR_LD=		-lpthread
.endif

post-extract:
	@${CP} ${WRKSRC}/Makefile.config.freebsd ${WRKSRC}/Makefile.config

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/X11R6,${LOCALBASE},g" \
		-e "s,/usr/local,${LOCALBASE},g" \
		-e "s,^\(BINDIR[ \t]*=\).*,\1${STAGEDIR}${PREFIX}/bin,g" \
		-e "s,^\(RANLIB[ \t]*=\).*,\1ranlib,g" \
		-e "s,^#\(LIBDIR[ \t]*=\).*,\1${PREFIX}/${OCAML_LIBDIR},g" \
		-e "s,^#\(DLLDIR[ \t]*=\).*,\1${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lablGL,g" \
		-e "s,^#\(INSTALLDIR[ \t]*=\).*,\1${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lablGL,g" \
		-e "s!^#\(COPTS[ \t]*=\).*!\1-c ${CFLAGS}!g" \
		-e "/^TKINCLUDES/s,=.*$$,= -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}," \
		-e "/^TKLIBS/s,=.*$$,= -L${LOCALBASE}/lib -ltk${TK_SHLIB_VER}\
		-ltcl${TCL_SHLIB_VER} ${THR_LD}," \
		${WRKSRC}/Makefile.config

	@${REINPLACE_CMD} -E \
		-e '/exec ocaml/s,\$$\(INSTALLDIR\),${PREFIX}/lib/ocaml/lablGL,' \
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e '/^OCAMLINC=/s,\+labltk,+site-lib/labltk -I +labltk,' \
		${WRKSRC}/src/Makefile ${WRKSRC}/LablGlut/src/Makefile \
		${WRKSRC}/Togl/src/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/lablglut
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/togl
	@(cd ${WRKSRC}/LablGlut/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/lablglut '! -name Makefile')
	@(cd ${WRKSRC}/Togl/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/togl '! -name Makefile')
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lablGL/dlllablgl.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lablGL/dlllablglut.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lablGL/dlltogl.so

.include <bsd.port.mk>
