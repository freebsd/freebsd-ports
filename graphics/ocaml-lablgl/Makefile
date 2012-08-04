# New ports collection makefile for:    lablgl
# Date created:         13. January 2002
# Whom:                 Ronald Kuehn <rk@ronald.org>
#
# $FreeBSD$
#

PORTNAME=	lablgl
PORTVERSION=	20120306
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/lsl/dist/ \
		https://forge.ocamlcore.org/frs/download.php/816/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	bf@FreeBSD.org
COMMENT=	OpenGL interface for Objective Caml

LICENSE=	BSD

WRKSRC=		${WRKDIR}/lablGL
USE_XORG=	x11 xext xmu
USE_GL=		glut
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_WASH=	yes
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	THREADS "Use a threaded Tcl/Tk (must match lang/ocaml)" on

PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

DOCSDIR=	${PREFIX}/share/doc/ocaml/lablgl
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/lablgl

CONFLICTS=	ocaml-notk-[0-9]* ocaml-nox11-[0-9]*

.include <bsd.port.pre.mk>

USE_TK=		84+
INVALID_TK_VER =	86
.if defined(WITH_THREADS)
USE_TK_THREADS =	yes
THR_CPP=	${PTHREAD_CFLAGS}
THR_LD =	${PTHREAD_LIBS}
.endif
.include "${PORTSDIR}/Mk/bsd.tcl.mk"

post-extract:
	@${CP} ${WRKSRC}/Makefile.config.freebsd ${WRKSRC}/Makefile.config

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/X11R6,${LOCALBASE},g" \
		-e "s,/usr/local,${LOCALBASE},g" \
		-e "s,^\(BINDIR[ \t]*=\).*,\1${PREFIX}/bin,g" \
		-e "s,^\(RANLIB[ \t]*=\).*,\1ranlib,g" \
		-e "s,^#\(LIBDIR[ \t]*=\).*,\1${PREFIX}/lib/ocaml,g" \
		-e "s,^#\(DLLDIR[ \t]*=\).*,\1${PREFIX}/lib/ocaml/stublibs,g" \
		-e "/^TKINCLUDES/s,=.*$$,= -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}," \
		-e "/^TKLIBS/s,=.*$$,= -L${LOCALBASE}/lib -ltk${TK_VER:S/.//}${_TCL_THREADS_SUFFIX}\
		-ltcl${TCL_VER:S/.//}${_TCL_THREADS_SUFFIX} ${THR_LD}," \
		${WRKSRC}/Makefile.config

	@${REINPLACE_CMD} \
		-e "s,^\(INSTALLDIR[ \t]*=\).*,\1${PREFIX}/lib/ocaml/lablGL,g" \
		-e "s!^\(COPTS[ \t]*=\).*!\1-c ${CFLAGS} ${THR_CPP}!g" \
		${WRKSRC}/Makefile.common ${WRKSRC}/Makefile

	@${REINPLACE_CMD} -E \
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		${WRKSRC}/src/Makefile ${WRKSRC}/LablGlut/src/Makefile \
		${WRKSRC}/Togl/src/Makefile

pre-install:
#
# XXX: for incorrect PREFIX. Really should be done in bsd.ocaml.mk...
#
.if !exists(${PREFIX}/lib/ocaml/stublibs)
	@${MKDIR} ${PREFIX}/lib/ocaml/stublibs
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}/lablglut
	@${MKDIR} ${EXAMPLESDIR}/togl
	@(cd ${WRKSRC}/LablGlut/examples && ${COPYTREE_SHARE} \* \
		${EXAMPLESDIR}/lablglut '! -name Makefile')
	@(cd ${WRKSRC}/Togl/examples && ${COPYTREE_SHARE} \* \
		${EXAMPLESDIR}/togl '! -name Makefile')
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
